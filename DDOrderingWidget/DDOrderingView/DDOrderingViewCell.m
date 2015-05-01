//
//  DDOrderingViewCell.m
//  DDOrderingView
//
//  Created by Vinod Rathod on 08/03/15.
//  Copyright (c) 2015 Vinod Rathod. All rights reserved.
//

#import "DDOrderingViewCell.h"


@implementation DDOrderingViewCell

- (void)awakeFromNib {
    // Initialization code
}

-(void)setOrderingModel:(DDOrderingModel *)orderingModel {
    _orderingModel = orderingModel;
    
    CGSize size = CGSizeMake(_orderingModel.width, _orderingModel.height);
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        UIImage *image = [self loadImageWithUrlString:_orderingModel.imageName];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            self.imageView.frame = CGRectMake(0, 0, size.width, size.height);
            self.imageView.image = image;
            self.tag = _orderingModel.value;
            NSLog(@"Tag value is %ld",(long)self.tag);
        });
    });
}

-(UIImage *)loadImageWithUrlString:(NSString *)urlString {
    NSURL *url = [NSURL URLWithString:urlString];
    NSData *data = [NSData dataWithContentsOfURL:url];
    UIImage *image = [UIImage imageWithData:data scale:[[UIScreen mainScreen] scale]];
    return image;
}

- (void)setHighlighted:(BOOL)highlighted {
    [super setHighlighted:highlighted];
    self.imageView.alpha = highlighted ? 0.75f : 1.0f;
}
@end
