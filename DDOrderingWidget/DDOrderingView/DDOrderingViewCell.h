//
//  DDOrderingViewCell.h
//  DDOrderingView
//
//  Created by Vinod Rathod on 08/03/15.
//  Copyright (c) 2015 Vinod Rathod. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DDOrderingModel.h"

@interface DDOrderingViewCell : UICollectionViewCell
@property (weak, nonatomic) IBOutlet UIImageView *imageView;
@property (strong, nonatomic) DDOrderingModel *orderingModel;
@property (nonatomic) NSString *imageUrlString;
@property (nonatomic) CGFloat width;
@property (nonatomic) CGFloat height;
@property (nonatomic) CGFloat value;

@end
