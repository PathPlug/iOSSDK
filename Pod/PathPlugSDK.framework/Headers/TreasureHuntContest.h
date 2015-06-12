//
//  TreasureHuntContest.h
//  PathPlugSDK
//
//  Created by Berk Taner on 27/04/15.
//  Copyright (c) 2015 I. All rights reserved.
//

#import <Foundation/Foundation.h>
@class TreasureHuntStep;

@interface TreasureHuntContest : NSObject

@property (nonatomic,retain) NSNumber *contest_id;
@property (nonatomic,retain) NSString *name;
@property (nonatomic,retain) NSString *welcome_text;
@property (nonatomic,retain) NSString *welcome_title;
@property (nonatomic,retain) NSString *welcome_button_text;
@property (nonatomic,retain) NSString *fail_text;
@property (nonatomic,retain) NSString *fail_button_text;
@property (nonatomic,retain) NSString *fail_image;
@property (nonatomic,retain) NSString *should_repeat;

@property (nonatomic,retain) NSMutableArray *hasStep;

@end
@interface TreasureHuntContest (CoreDataGeneratedAccessors)

- (void)addHasStepObject:(TreasureHuntStep *)value;
- (void)removeHasStepObject:(TreasureHuntStep *)value;
- (void)addHasStep:(NSMutableArray *)values;
- (void)removeHasStep:(NSMutableArray *)values;
@end