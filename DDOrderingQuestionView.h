//
//  DDOrderingQuestionView.h
//  DDOrderingView
//
//  Created by Vinod Rathod on 08/03/15.
//  Copyright (c) 2015 Vinod Rathod. All rights reserved.
//

#import "BasicQuestionWidget.h"

@interface DDOrderingQuestionView : BasicQuestionWidget
{
    NSMutableArray *localObjects;
}
@property (weak, nonatomic) IBOutlet UILabel *questionLabel;
- (IBAction)submitPressed:(id)sender;

@end
