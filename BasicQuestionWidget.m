//
//  BasicQuestionWidget.m
//  Learn&Earn
//
//  Created by Vadim on 16/1/15.
//  Copyright (c) 2015 Hiperware Pte Ltd. All rights reserved.
//

#import "BasicQuestionWidget.h"
#import "Consts.h"

@implementation BasicQuestionWidget

- (id)initWithFrame:(CGRect)frame {
    // override frame
    CGRect newFrame = frame;
    newFrame.size.height = 0.f;
    // set width of parent scroll view in ChildPracticeView
    newFrame.size.width = 664.f;
    
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
        _answer = [NSMutableDictionary dictionary];
    }
    return self;
}

- (NSError*) validateInput {
    return makeError(@"BasicQuestionWidget", E_APP, @"BasicQuestionWidget: You must override validateInput!");
}

@end
