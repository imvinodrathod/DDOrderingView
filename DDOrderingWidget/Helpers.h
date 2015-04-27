//
//  Helpers.h
//  Outliers
//
//  Created by Vadim on 3/2/14.
//  Copyright (c) 2014 Hiperware Pte Ltd. All rights reserved.
//


#ifndef Outliers_Helpers_h
#define Outliers_Helpers_h

#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>
#import "Consts.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"

// do not use __logm directly
// use logm macro instead
static void __logm(id msg) {
    NSLog(@"%@", msg);
}

static void loge(id err) {
    NSLog(@"OOOOOOOOOOOOOOOOPS: %@", err);
}

static void logw(id warn) {
    NSLog(@"WARNING: %@", warn);
}

static void todo(id what) {
    NSLog(@"--------------------------------> TODO: %@", what);
}


#ifdef NO_DEBUG
    #define logm(...)
#else
    #define logm __logm
#endif

#define degreesToRadians(degrees) (M_PI * degrees / 180.0f)
#define radiansToDegrees(radians) (radians * 180.0f / M_PI)

typedef void (^Block)();
typedef void (^BoolBlock)(BOOL value);
typedef void (^SimpleBlock)(id object);
typedef void (^CommonBlock)(NSError *err, id object);
typedef void (^DialogMessageBlock)(BOOL isCancelled);
typedef void (^DialogMessageBlockEx)(BOOL isCancelled, id data);

typedef void (^KeyboardDisplayBlock)(BOOL display, UITextField *field, NSString *kind);

// data source handler types
typedef NSInteger (^ListGetCountBlock)(UITableView *tableView, NSInteger section);
typedef UITableViewCell* (^ListGetCellBlock)(UITableView *tableView, NSIndexPath *indexPath);
typedef void (^ListCellBlock)(UITableView *tableView, UITableViewCell* cell, id data);



static NSUInteger normalizeCoins(NSUInteger coins) {
    if (coins == 0)
        return coins;
    NSUInteger normalizedCoins = coins / 100;
    normalizedCoins *= 100;
    if (normalizedCoins == 0) {
        NSUInteger normalizedCoins = coins / 10;
        normalizedCoins *= 10;
    }
    if (normalizedCoins == 0) {
        NSUInteger normalizedCoins = coins / 5;
        normalizedCoins *= 5;
    }
    if (normalizedCoins == 0) {
        NSUInteger normalizedCoins = coins / 2;
        normalizedCoins *= 2;
    }
    return normalizedCoins;
}

static NSString* formatDecimal(NSUInteger number) {
    // formatting
    NSNumberFormatter *formatter = [NSNumberFormatter new];
    [formatter setNumberStyle:NSNumberFormatterDecimalStyle];
    return [formatter stringFromNumber:[NSNumber numberWithUnsignedInteger:number]];
}


static NSError* makeError(const NSString *domain, const NSInteger code, const NSString *message) {
    NSString *sdomain = nil;
    if (domain == nil || [domain length] == 0) {
        sdomain = @"Outliers";
    } else {
        sdomain = [NSString stringWithFormat:@"%@", domain];
    }
    NSDictionary *dict = [NSDictionary dictionaryWithObject:message forKey:NSLocalizedDescriptionKey];
    NSError *error = [NSError errorWithDomain:sdomain code:code userInfo:dict];
    return error;
}

static UIFont* AceAgeFont(CGFloat size) {
    return [UIFont fontWithName:@"iceaGErUSS" size:size];
}

static UIFont* NexaFont(CGFloat size) {
    return [UIFont fontWithName:@"NexaBold" size:size];
}

static UIFont* ChillerFont(CGFloat size) {
    return [UIFont fontWithName:@"Chiller-Regular" size:size];
}

static UIFont* HandFont(CGFloat size) {
    return [UIFont fontWithName:@"BradleyHandITC" size:size];
}

// ====================================

static UIFont* BangFont(CGFloat size) {
    return [UIFont fontWithName:@"bangwhackpow" size:size];
}

static UIFont* ChinaCatFont(CGFloat size) {
    return [UIFont fontWithName:@"Chinacat" size:size];
}

static UIFont* EdsonFont(CGFloat size) {
    return [UIFont fontWithName:@"Edson_Comics_Bold-Bold" size:size];
}

static UIFont* UntukIbuFont(CGFloat size) {
    return [UIFont fontWithName:@"--unknown-1--" size:size];
}

static UIFont* GoBoomFont(CGFloat size) {
    return [UIFont fontWithName:@"GoBoom!" size:size];
}

static UIFont* KomikaFont(CGFloat size) {
    return [UIFont fontWithName:@"KomikaText-Bold" size:size];
}

static UIFont* WetinFont(CGFloat size) {
    return [UIFont fontWithName:@"WetinCaroWant" size:size];
}

// ====================================


static UIColor* RedTextColor() {
    return [UIColor colorWithRed:173.0f/255 green:24.0f/255 blue:34.0f/255 alpha:1.0f];
}

static UIColor* YellowTextColor() {
    return [UIColor colorWithRed:296.0f/255 green:230.0f/255 blue:96.0f/255 alpha:1.0f];
}

static UIColor* GreenTextColor() {
    return [UIColor colorWithRed:5.0f/255 green:94.0f/255 blue:2.0f/255 alpha:1.0f];
}

static UIColor* YellowBackgroundColor() {
    return [UIColor colorWithRed:251.0f/255 green:232.0f/255 blue:126.0f/255 alpha:1.0f];
}

static void setControlFont(id control, UIFont *font, UIColor *color) {
    if ([control isKindOfClass:[UILabel class]]) {
        UILabel *label = control;
        label.font = font;
        label.textColor = color;
    } else if ([control isKindOfClass:[UIButton class]]) {
        UIButton *button = control;
        button.titleLabel.font = font;
        [button setTitleColor:color forState:UIControlStateHighlighted];
        [button setTitleColor:color forState:UIControlStateNormal];
        [button setTitleColor:color forState:UIControlStateSelected];
    } else if ([control isKindOfClass:[UITextField class]]) {
        UITextField *field = control;
        field.font = font;
        field.textColor = color;
    } else if ([control isKindOfClass:[UITextView class]]) {
        UITextView *view = control;
        BOOL editable = view.editable;
        if (!editable)
            view.editable = YES;
        view.font = font;
        view.textColor = color;
        if (!editable)
            view.editable = editable;
    }
}

static void setControlWhiteHandFont(id control, CGFloat size) {
    setControlFont(control, HandFont(size), [UIColor whiteColor]);
}

static void setControlWhiteChillerFont(id control, CGFloat size) {
    setControlFont(control, HandFont(size), [UIColor whiteColor]);
}

static void setControlRedFont(id control, CGFloat size) {
    setControlFont(control, AceAgeFont(size), RedTextColor());
}

static void setControlYellowFont(id control, CGFloat size) {
    setControlFont(control, AceAgeFont(size), YellowTextColor());
}

static void setControlGreenFont(id control, CGFloat size) {
    setControlFont(control, AceAgeFont(size), GreenTextColor());
}

static void setControlRedNexaFont(id control, CGFloat size) {
    setControlFont(control, NexaFont(size), RedTextColor());
}

static void setControlYellowNexaFont(id control, CGFloat size) {
    setControlFont(control, NexaFont(size), YellowTextColor());
}

static void setControlGreenNexaFont(id control, CGFloat size) {
    setControlFont(control, NexaFont(size), GreenTextColor());
}

// randomly shuffles array
static NSArray* shuffleArray(NSArray *array) {
    if (!array || array.count < 2)
        return array;
    NSMutableArray *newArray = [NSMutableArray arrayWithArray:array];
    NSUInteger count = array.count;
    for (NSUInteger i = 0; i < count; ++i) {
        NSInteger remainingCount = count - i;
        NSInteger exchangeIndex = i + arc4random_uniform(remainingCount);
        [newArray exchangeObjectAtIndex:i withObjectAtIndex:exchangeIndex];
    }
    return newArray;
}

// returns:
// 2: finished objective
// 1: ahead schedule
// 0: on schedule
// -1: behind schedule
static NSInteger getScheduleState(NSDictionary* objective) {
    if ([objective[@"goal"] boolValue]) {
        // completed
        return 2;
    }
    
    // allowed error rate in seconds for calculation
    static const NSUInteger errorRate = 1 * 30; // +/- 30 secs
    NSUInteger days = [objective[@"days"] unsignedIntegerValue];
    NSUInteger days_passed = [objective[@"days_passed"] unsignedIntegerValue];
    NSUInteger mintime_per_day = [objective[@"mintime_per_day"] unsignedIntegerValue];
    NSUInteger expected_time = mintime_per_day * (days < days_passed ? days : days_passed + 1);
    NSUInteger timespent = [objective[@"timespent"] unsignedIntegerValue];
    BOOL expired = [objective[@"expired"] boolValue];
    
    if (timespent > (expected_time - errorRate) && timespent < (expected_time + errorRate)) {
        // time spent on objective is within allowed bounds
        // on schedule
        return expired ? -1 : 0;
    } else if (timespent > (expected_time + errorRate)) {
        // ahead of schedule
        return 1;
    } else {
        // behind schedule
        return -1;
    }
}

static NSString* getIconNameForAchievementId(NSUInteger achievementId) {
    NSString *pictureId;
    
    if (achievementId == ACHIEVEMENT_FASTEST_TIME)
        pictureId = @"300";
    else if (achievementId >= ACHIEVEMENT_CORRECT_IN_ROW_5 && achievementId < ACHIEVEMENT_CORRECT_IN_ROW_100)
        pictureId = @"400";
    else
        pictureId = @"empty";
    
    NSString *pictureName = [NSString stringWithFormat:@"screen-elem-cup-%@", pictureId];
    return pictureName;
}

static NSString* getLabelForAchievementId(NSUInteger achievementId) {
    NSString *label;
    
    if (achievementId == ACHIEVEMENT_FASTEST_TIME)
        label = @""; //S_ACHIEVEMENT_FASTEST_TIME;
    else if (achievementId == ACHIEVEMENT_CORRECT_IN_ROW_5)
        label = @"5";//[NSString stringWithFormat:S_ACHIEVEMENT_CORRECT_IN_ROW, 5];
    else if (achievementId == ACHIEVEMENT_CORRECT_IN_ROW_10)
        label = @"10";//[NSString stringWithFormat:S_ACHIEVEMENT_CORRECT_IN_ROW, 10];
    else if (achievementId == ACHIEVEMENT_CORRECT_IN_ROW_20)
        label = @"20";//[NSString stringWithFormat:S_ACHIEVEMENT_CORRECT_IN_ROW, 20];
    else if (achievementId == ACHIEVEMENT_CORRECT_IN_ROW_30)
        label = @"30";//[NSString stringWithFormat:S_ACHIEVEMENT_CORRECT_IN_ROW, 30];
    else if (achievementId == ACHIEVEMENT_CORRECT_IN_ROW_40)
        label = @"40";//[NSString stringWithFormat:S_ACHIEVEMENT_CORRECT_IN_ROW, 40];
    else if (achievementId == ACHIEVEMENT_CORRECT_IN_ROW_50)
        label = @"50";//[NSString stringWithFormat:S_ACHIEVEMENT_CORRECT_IN_ROW, 50];
    else if (achievementId == ACHIEVEMENT_CORRECT_IN_ROW_60)
        label = @"60";//[NSString stringWithFormat:S_ACHIEVEMENT_CORRECT_IN_ROW, 60];
    else if (achievementId == ACHIEVEMENT_CORRECT_IN_ROW_70)
        label = @"70";//[NSString stringWithFormat:S_ACHIEVEMENT_CORRECT_IN_ROW, 70];
    else if (achievementId == ACHIEVEMENT_CORRECT_IN_ROW_80)
        label = @"80";//[NSString stringWithFormat:S_ACHIEVEMENT_CORRECT_IN_ROW, 80];
    else if (achievementId == ACHIEVEMENT_CORRECT_IN_ROW_90)
        label = @"90";//[NSString stringWithFormat:S_ACHIEVEMENT_CORRECT_IN_ROW, 90];
    else if (achievementId == ACHIEVEMENT_CORRECT_IN_ROW_100)
        label = @"100";//[NSString stringWithFormat:S_ACHIEVEMENT_CORRECT_IN_ROW, 100];
    else
        label = @"";
    
    return label;
}

static NSDate* stripTime(NSDate* date) {
    unsigned int flags = NSYearCalendarUnit|NSMonthCalendarUnit|NSDayCalendarUnit;
    NSCalendar *calendar = [NSCalendar currentCalendar];
    calendar.timeZone = [NSTimeZone timeZoneWithAbbreviation:@"UTC"];
    NSDateComponents *components = [calendar components:flags fromDate:date];
    return [calendar dateFromComponents:components];
}

// returns:
// -1: date is before today
// 0: date is today
// 1: date is ahead of today
static NSInteger getOffsetForDate(NSDate* value) {
    NSDate *date = stripTime(value);
    NSDate *today = stripTime([NSDate date]);
    NSTimeInterval interval = [date timeIntervalSinceDate:today];
    if (interval == 0)
        // same day
        return 0;
    else if (interval < 0)
        // before today
        return -1;
    else
        // after today
        return 1;
}

static void scaleViewAnimation(UIView *view, CGFloat scaleFactor, void (^animationCompleted)(void)) {
    [UIView animateWithDuration:0.2f
                          delay:0.0f
                        options:UIViewAnimationOptionAllowAnimatedContent
                     animations:^{
                         view.transform = CGAffineTransformMakeScale(scaleFactor, scaleFactor);
                     }
                     completion:^(BOOL finished) {
                         if (animationCompleted)
                             animationCompleted();
                     }];
}

static void pulseViewAnimation(UIView *view, void (^animationCompleted)(void)) {
    [UIView animateWithDuration:0.1f
                          delay:0.0f
                        options:UIViewAnimationOptionAllowAnimatedContent
                     animations:^{
                         view.transform = CGAffineTransformMakeScale(0.97f, 0.97f);
                     }
                     completion:^(BOOL finished) {
                         [UIView animateWithDuration:0.1f
                                               delay:0.0f
                                             options:UIViewAnimationOptionAllowAnimatedContent
                                          animations:^{
                                              view.transform = CGAffineTransformMakeScale(1.02f, 1.02f);
                                          }
                                          completion:^(BOOL finished) {
                                              [UIView animateWithDuration:0.1f
                                                                    delay:0.0f
                                                                  options:UIViewAnimationOptionAllowAnimatedContent
                                                               animations:^{
                                                                   view.transform = CGAffineTransformMakeScale(1.0f, 1.0f);
                                                               }
                                                               completion:^(BOOL finished) {
                                                                   if (animationCompleted)
                                                                       animationCompleted();
                                                               }];
                                          }];
                     }];
}

static void bringViewAnimation(UIView *view, void (^animationCompleted)(void)) {
    view.transform = CGAffineTransformMakeScale(0.0f, 0.0f);
    [UIView animateWithDuration:0.2f
                          delay:0.0f
                        options:UIViewAnimationOptionAllowAnimatedContent
                     animations:^{
                         view.transform = CGAffineTransformMakeScale(1.2f, 1.2f);
                     }
                     completion:^(BOOL finished) {
                         [UIView animateWithDuration:0.1f
                                               delay:0.0f
                                             options:UIViewAnimationOptionAllowAnimatedContent
                                          animations:^{
                                              view.transform = CGAffineTransformMakeScale(0.8f, 0.8f);
                                          }
                                          completion:^(BOOL finished) {
                                              [UIView animateWithDuration:0.05f
                                                                    delay:0.0f
                                                                  options:UIViewAnimationOptionAllowAnimatedContent
                                                               animations:^{
                                                                   view.transform = CGAffineTransformMakeScale(1.0f, 1.0f);
                                                               }
                                                               completion:^(BOOL finished) {
                                                                   if (animationCompleted)
                                                                       animationCompleted();
                                                               }];
                                          }];
                     }];
}

static BOOL isValid(id object) {
    BOOL result = NO;
    if (object != nil && object != (id)[NSNull null]) {
        result = YES;
    }
    return result;
}

static BOOL isValidEmail(NSString *checkString) {
    BOOL stricterFilter = YES;
    NSString *stricterFilterString = @"[A-Z0-9a-z\\._%+-]+@([A-Za-z0-9-]+\\.)+[A-Za-z]{2,4}";
    NSString *laxString = @".+@([A-Za-z0-9]+\\.)+[A-Za-z]{2}[A-Za-z]*";
    NSString *emailRegex = stricterFilter ? stricterFilterString : laxString;
    NSPredicate *emailTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", emailRegex];
    return [emailTest evaluateWithObject:checkString];
}

// convert JS JSON date string to NSDate
static NSDate* JSDateToNSDate(NSString *rfc3339DateTimeString) {
	NSDateFormatter *rfc3339DateFormatter = [[NSDateFormatter alloc] init];
    [rfc3339DateFormatter setTimeZone:[NSTimeZone localTimeZone]];
	[rfc3339DateFormatter setDateFormat:@"yyyy'-'MM'-'dd'T'HH':'mm':'ss'.'SSS'Z'"];
	[rfc3339DateFormatter setTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:0]];
	// Convert the RFC 3339 date time string to an NSDate.
	NSDate *result = [rfc3339DateFormatter dateFromString:rfc3339DateTimeString];
	return result;
}

// returns date string, e.g.: 2014-12-17
static NSString* dateSimpleString(NSDate *date) {
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"yyyy-MM-dd"];
    return [formatter stringFromDate:date];
}

static NSDate* UTCDateToLocalDate(NSDate *UTCDate) {
    NSTimeZone *tz = [NSTimeZone defaultTimeZone];
    NSInteger seconds = [tz secondsFromGMTForDate:UTCDate];
    return [NSDate dateWithTimeInterval:seconds sinceDate:UTCDate];
}

static BOOL saveObjectToFile(id object, NSString *fullPath) {
    NSData *data = [NSKeyedArchiver archivedDataWithRootObject:object];
    return [data writeToFile:fullPath atomically:YES];
}

static id loadObjectFromFile(NSString *fullPath) {
    NSData *data = [NSData dataWithContentsOfFile:fullPath];
    return [NSMutableDictionary dictionaryWithDictionary:[NSKeyedUnarchiver unarchiveObjectWithData:data]];
}

static id loadWidget(NSString* xibName) {
    UIView *view = [[[UIViewController alloc] initWithNibName:xibName bundle:nil] view];
    return [view initWithFrame:CGRectNull];
}

#pragma clang diagnostic pop

#endif


