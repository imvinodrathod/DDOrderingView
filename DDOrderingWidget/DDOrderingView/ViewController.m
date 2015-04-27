//
//  ViewController.m
//  DDOrderingView
//
//  Created by Vinod Rathod on 08/03/15.
//  Copyright (c) 2015 Vinod Rathod. All rights reserved.
//

#import "ViewController.h"
#import "DDOrderingQuestionView.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    DDOrderingQuestionView *view = loadWidget(@"DDOrderingQuestionView");
    view.frame = CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height);
    [self.view addSubview: view];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
