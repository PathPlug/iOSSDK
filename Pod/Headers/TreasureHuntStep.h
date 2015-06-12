//
//  TreasureHuntStep.h
//  PathPlugSDK
//
//  Created by Berk Taner on 27/04/15.
//  Copyright (c) 2015 I. All rights reserved.
//

#import <Foundation/Foundation.h>
@class Beacon;
@class TreasureHuntContest;
@interface TreasureHuntStep : NSObject

@property (nonatomic,retain) NSNumber *step_id;
@property (nonatomic,retain) NSNumber *step_order;
@property (nonatomic,retain) NSNumber *is_final_step;
@property (nonatomic,retain) NSNumber *distance;
@property (nonatomic,retain) NSNumber *duration;
@property (nonatomic,retain) NSString *image;
@property (nonatomic,retain) NSString *video;
@property (nonatomic,retain) NSString *title;
@property (nonatomic,retain) NSString *action_text;
@property (nonatomic,retain) NSString *success_video;
@property (nonatomic,retain) NSString *success_text;
@property (nonatomic,retain) NSString *success_title;
@property (nonatomic,retain) NSString *success_subtitle;
@property (nonatomic,retain) NSString *success_message;
@property (nonatomic,retain) NSString *success_continue_button_text;
@property (nonatomic,retain) NSString *success_final_button_text;


@property (nonatomic,retain) TreasureHuntContest *hasContest;


@property (nonatomic,retain) NSMutableArray *hasBeacon;

@end
@interface TreasureHuntStep (CoreDataGeneratedAccessors)

- (void)addHasBeaconObject:(Beacon *)value;
- (void)removeHasBeaconObject:(Beacon *)value;
- (void)addHasBeacon:(NSMutableArray *)values;
- (void)removeHasBeacon:(NSMutableArray *)values;
@end
