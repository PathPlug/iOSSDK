//
//  TreasureHuntManager.h
//  PathPlugSDK
//
//  Created by Berk Taner on 27/04/15.
//  Copyright (c) 2015 I. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import "TreasureHuntStep.h"
#import "TreasureHuntContest.h"

@class Beacon;
@class TreasureHuntManager;
@protocol TreasureHuntDelegate <NSObject>
@optional

-(void)treasureHuntManager:(TreasureHuntManager*)manager didRangeBeacon:(Beacon*)beacon;
-(void)treasureHuntManager:(TreasureHuntManager *)manager didReceiveAwardCode:(NSString*)awardCode;
@end



@interface TreasureHuntManager : NSObject

@property (nonatomic,retain) NSMutableArray *contest_array;
@property (nonatomic,retain) TreasureHuntContest *contest;
@property (nonatomic,retain) NSNumber *currentStepIndex;
@property (nonatomic,retain) NSMutableArray *currentRangedBeacons;
@property  float currentRangeDistance;


@property BOOL isRanging;
+(TreasureHuntManager*)treasurehuntManager;
+(TreasureHuntManager*)treasureHuntManagerWithContest:(TreasureHuntContest*)contest;

@property(nonatomic,assign) id<TreasureHuntDelegate> delegate;

-(void)setRandomContest;

-(void)startTreasureHunt;

-(void)stopTreasureHunt;
-(void)resetTreasureHunt;


-(void)startRanging;
-(void)stopRanging;

-(void)moveToNextStep;

-(void)failStep;
-(void)successStep;
-(void)goToFinalStep;


-(TreasureHuntStep*)getCurrentStepInfo;
-(TreasureHuntContest*)getCurrentContest;
-(int)totalSteps;
-(BOOL)checkForActiveBeacon:(Beacon*)beacon;
@end
