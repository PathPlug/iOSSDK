//
//  PathPlug.h
//  PathPlugSDK
//
//  Created by Berk Taner on 04/07/14.
//  Copyright (c) 2014 Arkenus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PlugData.h"
#import "Beacon.h"
#import "Interaction.h"
#import "VirtualTag.h"
#import "SmartNote.h"
#import "AudioSign.h"

#import "TreasureHuntManager.h"

@import CoreLocation;
@class PathPlug;


@protocol TreasureHuntDataDelegate <NSObject>
@optional

-(void)pathPlug:(PathPlug*)pathPlug didRangeBeacon:(Beacon*)beacon;
-(void)pathPlug:(PathPlug *)pathPlug didReceiveAwardCode:(NSDictionary*)result;
@end



/**
 *  PathPlugDelegate is delegate method to pass data from framework.
 */

@protocol PathPlugDelegate <NSObject>
@optional


/**
 *  Returns audio sign interaction information encapsulated in a Plug Data
 *
 *  @param pathPlug PathPlug Object
 *  @param data     PlugData Object
 */
-(void)pathPlug:(PathPlug*)pathPlug getAssistanceData:(PlugData*)data;
/**
 *  Returns real time sightings of Beacons and their distances
 *
 *  @param pathPlug PathPlug Object
 *  @param beacon   Beacon Object
 *  @param distance distance in meters
 */
-(void)pathPlug:(PathPlug *)pathPlug updatedBeaconData:(Beacon*)beacon andDistance:(double)distance;
/**
 *  Returns virtual tag interaction information encapsulated in a Plug Data
 *
 *  @param pathPlug PathPlug Object
 *  @param data     PlugData Object
 */
-(void)pathPlug:(PathPlug *)pathPlug getVirtualtagData:(PlugData*)data;

/**
 *  Fired when Heatmap is active and region enter/exit action happens
 *
 *  @param pathPlug PathPlug object
 *  @param data     check for actionType for Enter | Exit
 *  @param beacon   Beacon Object
 */
-(void)pathPlug:(PathPlug *)pathPlug getHeatmapData:(PlugData*)data forBeacon:(Beacon*)beacon;
/**
 *  Fired when a beacon with smartnote object is seen
 *
 *  @param pathPlug PathPlug object
 *  @param data     PlugData Object
 */
-(void)pathPlug:(PathPlug *)pathPlug getSmartNoteData:(PlugData*)data;


/**
 *  Fired when data is completely downloaded from API and ready to use
 *
 *  @param pathPlug PathPlug Object
 *  @param result   YES when download finished
 */
-(void)pathPlug:(PathPlug *)pathPlug isFrameworkReady:(BOOL)result;
@end
/**
 *  PathPlug Object. Heart and soul of framework
 */
@interface PathPlug : NSObject<CLLocationManagerDelegate>

//optional


/**
 *  Returns a singleton instance of PathPlug for you to use
 *
 *  @return PathPlug Object
 */
+(PathPlug*)sharedPlug;
/**
 *  You need to use API Key and Secret obtained from www.pathplug.com generated for your application.
 *
 *  @param app_key   key for your application
 *  @param appSecret secret for your application
 */
-(void)initWithAppKey:(NSString*)app_key andAppSecret:(NSString*)appSecret;
/**
 *  Reconnects to PathPlug server and updates information
 *
 */
-(void)reloadData;
/**
 *  Stops PathPlug Service
 */
-(void)stopService;
/**
 *  Starts PathPlug Service
 */
-(void)startService;

/**
 *  Gives you a list of beacons.
 *
 *  @return array of beacons
 */
-(NSArray*)getBeaconList;

@property(nonatomic,assign) id<PathPlugDelegate> delegate;
@property(nonatomic,assign) id<TreasureHuntDataDelegate> treasureHuntDataDelegate;
//time intervals for interactions
/**
 *  Refresh Interval for AudioSign Interaction
 */
@property (nonatomic) NSTimeInterval assitanceRefreshInterval;
/**
 *  Refresh Interval for Virtual Tag Interaction
 */
@property (nonatomic) NSTimeInterval virtualTagRefreshInterval;
/**
 *  Refresh Interval for Smart Note Interaction
 */
@property (nonatomic) NSTimeInterval smartNoteRefreshInterval;
//checker for invidiaul components




/**
 *  Refresh interval for data
 */
@property (nonatomic) NSTimeInterval dataRefreshInterval;

@property (nonatomic,retain) TreasureHuntManager *treasureHuntManager;

@property BOOL isFrameWorkLoaded;

-(void)postTresureHuntSightingWithStepID:(NSNumber*)stepID andBeacon:(Beacon*)beacon andDate:(NSDate*)date;
-(void)postTreasureHuntVisitorWithName:(NSString*)name lastName:(NSString*)lastname email:(NSString*)email gender:(NSString*)gender facebookLink:(NSString*)fb_link facebookID:(NSString*)fb_id;

-(void)addBeaconToMonitoring:(Beacon*)beacon;
-(void)removeBeaconFromMonitoring:(Beacon*)beacon;


-(void)enableHeatmap;
-(void)disableHeatmap;
-(void)enableVirtualTag;
-(void)disableVirtualTag;
-(void)enableSmartNote;
-(void)disableSmartNote;
-(void)enableAudioSign;
-(void)disableAudioSign;
-(void)enableAllBeacons;
-(void)disableAllBeacons;

-(void)calibrateBeacon:(Beacon*)beacon withRSSI:(int)RSSI;

@end
