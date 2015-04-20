//
//  BasicQuestionWidget.h
//  Learn&Earn
//
//  Created by Vadim on 16/1/15.
//  Copyright (c) 2015 Hiperware Pte Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Helpers.h"


@interface BasicQuestionWidget : UIView

// override setter in descendats to initialize widget
@property (strong, nonatomic) NSDictionary *question;

// call the block internally in descendants when you needed to show/hide keyboard
@property (strong, nonatomic) KeyboardDisplayBlock keyboardDisplayHandler;

// called when initialization completed, and pass error as argument if any
@property (strong, nonatomic) SimpleBlock initializationCompletedHandler;

// return answer dictionary
// answer format depends on question type
// use _answer in descendants to set answer values
@property (strong, nonatomic, readonly, getter=getAnswer) NSMutableDictionary *answer;

// override in descendants
// return nil if input is valid, otherwise NSError,
// i.e. when not all fields filled
- (NSError*) validateInput;

@end
