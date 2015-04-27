//
//  DDOrderingQuestionView.m
//  DDOrderingView
//
//  Created by Vinod Rathod on 08/03/15.
//  Copyright (c) 2015 Vinod Rathod. All rights reserved.
//

#import "DDOrderingQuestionView.h"
#import "LXReorderableCollectionViewFlowLayout.h"
#import "DDOrderingViewCell.h"
#import "DDOrderingModel.h"
#import "AppDelegate.h"

@interface DDOrderingQuestionView()
@property (weak, nonatomic) IBOutlet UICollectionView *collectionView;
@property (nonatomic) NSDictionary *objects;
@property (nonatomic) NSMutableArray *results;
@property (nonatomic) BOOL isSubmitPressed;
@property (nonatomic) NSArray *localAnswer;

@end

@implementation DDOrderingQuestionView

-(void)awakeFromNib {
    
    [self setQuestion:nil];
    
    localObjects = [NSMutableArray array];
    self.results = [NSMutableArray array];
    
    self.collectionView.backgroundColor = [UIColor whiteColor];
    
    
    LXReorderableCollectionViewFlowLayout *flowLayout = [[LXReorderableCollectionViewFlowLayout alloc]init];
    flowLayout.scrollDirection = UICollectionViewScrollDirectionVertical;
    flowLayout.itemSize = CGSizeMake(50.0, 50.0);
    [self.collectionView setCollectionViewLayout:flowLayout];
    
    // Register the collection cell
    [self.collectionView registerNib:[UINib nibWithNibName:@"DDOrderingViewCell" bundle:nil] forCellWithReuseIdentifier:@"DDOrderingViewCell"];
    
//    self.objects = [self loadObjects];
    
    

    
}

-(void)downloadDataFromURL:(NSURL *)url withCompletionHandler:(void (^)(NSData *))completionHandler{
    // Instantiate a session configuration object.
    NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
    
    // Instantiate a session object.
    NSURLSession *session = [NSURLSession sessionWithConfiguration:configuration];
    
    // Create a data task object to perform the data downloading.
    NSURLSessionDataTask *task = [session dataTaskWithURL:url completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        
        if (error != nil) {
            // If any error occurs then just display its description on the console.
            NSLog(@"%@", [error localizedDescription]);
        }
        else{
            // If no error occurs, check the HTTP status code.
            NSInteger HTTPStatusCode = [(NSHTTPURLResponse *)response statusCode];
            
            // If it's other than 200, then show it on the console.
            if (HTTPStatusCode != 200) {
                NSLog(@"HTTP status code = %ld", (long)HTTPStatusCode);
            }
            
            // Call the completion handler with the returned data on the main thread.
            [[NSOperationQueue mainQueue] addOperationWithBlock:^{
                completionHandler(data);
            }];
        }
    }];
    
    // Resume the task.
    [task resume];
}


-(void)setQuestion:(NSDictionary *)question {
    [super setQuestion:question];
    
    NSURL *url = [NSURL URLWithString:@"http://pupus.web44.net/vinodrathod/meta_ordering.json"];
    [self downloadDataFromURL:url withCompletionHandler:^(NSData *data) {
        if (data != nil) {
            NSLog(@"Loading json data");
            
            NSError *error;
            NSMutableDictionary *returnedDictionary = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingAllowFragments error:&error];
            if (error != nil) {
                NSLog(@"%@", [error localizedDescription]);
            } else {
                self.objects = [returnedDictionary objectForKey:@"objects"];
                NSLog(@"%@",returnedDictionary);
                
                for (int i=0; i<self.objects.count; i++) {
                    NSString *urlInString = [[self.objects valueForKey:@"image"]objectAtIndex:i];
                    CGFloat width = [[[self.objects valueForKeyPath:@"object.width"]objectAtIndex:i]floatValue];
                    CGFloat height = [[[self.objects valueForKeyPath:@"object.height"]objectAtIndex:i]floatValue];
                    CGFloat value = [[[self.objects valueForKey:@"value"]objectAtIndex:i]floatValue];
                    
                    DDOrderingModel *model = [[DDOrderingModel alloc]init];
                    model.imageName = urlInString;
                    model.width = width;
                    model.height = height;
                    model.value = value;
                    [localObjects addObject:model];
                }
                
                self.questionLabel.text = [NSString stringWithFormat:@"%@",[returnedDictionary objectForKey:@"question"]];
                self.localAnswer = [returnedDictionary objectForKey:@"answer"];
                
                [self.collectionView reloadData];
                
            }
        }
        
    }];
}




#pragma mark - Collection View

-(NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
    return 1;
}

-(NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    return localObjects.count;
}

-(UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {

    DDOrderingViewCell *cell =[collectionView dequeueReusableCellWithReuseIdentifier:@"DDOrderingViewCell" forIndexPath:indexPath];
    
    if (localObjects!=nil) {
        
        DDOrderingModel *cellModel = localObjects[indexPath.item];
        cell.orderingModel = cellModel;
        
    }
    
    
    return cell;
}

#pragma mark - LXReorderableCollectionViewDataSource methods

- (void)collectionView:(UICollectionView *)collectionView itemAtIndexPath:(NSIndexPath *)fromIndexPath willMoveToIndexPath:(NSIndexPath *)toIndexPath {
    DDOrderingModel *model = localObjects[fromIndexPath.item];
    
    [localObjects removeObjectAtIndex:fromIndexPath.item];
    [localObjects insertObject:model atIndex:toIndexPath.item];
}


- (UIEdgeInsets)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout insetForSectionAtIndex:(NSInteger)section {
    // return UIEdgeInsetsMake(0,8,0,8);  // top, left, bottom, right
    return UIEdgeInsetsMake(5,5,5,5);  // top, left, bottom, right
}

- (IBAction)submitPressed:(id)sender {
    
//    if (!self.isSubmitPressed) {
//        self.isSubmitPressed = YES;
        for (int i=0; i<localObjects.count; i++) {
            NSIndexPath *indexpath = [NSIndexPath indexPathForItem:i inSection:0];
            UICollectionViewCell *cell = [self.collectionView cellForItemAtIndexPath:indexpath];
            NSNumber *value = [NSNumber numberWithInt:cell.tag];
            [self.results addObject:value];
        }
    
    NSString *answerLabel;
    if ([self.results isEqualToArray:self.localAnswer]) {
        answerLabel = @"Correct";
    } else
        answerLabel = @"Incorrect";
    
    UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"Result" message:[NSString stringWithFormat:@"Your Answer is %@",answerLabel] delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
    [alert show];
    [self.results removeAllObjects];
}
@end
