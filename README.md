# PathPlug


[![Version](https://img.shields.io/cocoapods/v/PathPlug.svg?style=flat)](http://cocoapods.org/pods/PathPlug)
[![License](https://img.shields.io/cocoapods/l/PathPlug.svg?style=flat)](http://cocoapods.org/pods/PathPlug)
[![Platform](https://img.shields.io/cocoapods/p/PathPlug.svg?style=flat)](http://cocoapods.org/pods/PathPlug)

## Usage

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements
- PathPlug offers two flawors of our SDK. 
libPathPlug.a is developer who want to support iOS7.  From iOS8 and onward we'll publish our sdk as PathPlugSDK.framework.

- Auto Reference Counting (ARC)

  - PathPlug requires ARC.

## Installation

PathPlug is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod "PathPlugSDK"
```

Alternatively you can clone this repo and use PathPlugSDK.framework or libPathPlugSDK.a found under /Pod/ directory.
Setup
----------------------------------
### PrefixHeader.pch
You can import PathPlugSDK on PrefixHeader for easy access (optional)

      #import <PathPlugSDK/PathPlugSDK.h>


### Configuring PathPlug

You'll be needing two keys App Key and App Secret. You can get those from www.pathlug.com . You can perform setup on any view controller, like example shown below:


    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
    {

      // Override point for customization after application launch.

      // ...#import <PathPlugSDK/PathPlugSDK.h>

      [[PathPlug sharedPlug] initWithAppKey:@"AppKey" andAppSecret:@"AppSecret"];

      // ...

      return YES;
    }

###Singleton Object

PathPlugSDK initialises a singleton object that you can use anywhere on your app.

  	PathPlug *pathPlug = [PathPlug sharedPlug];

###Service Methods

 Stops PathPlug Service

    – stopService

Starts PathPlug Service

    – startService

Returns NSArray* of beacons for app

    – getBeaconList

###Beacon Methods

Add Beacon

	-(void)addBeaconToMonitoring:(Beacon*)beacon;
Remove Beacon

	-(void)removeBeaconFromMonitoring:(Beacon*)beacon;

##Enabling Interactions
You have total control on which interactions should be handled by PathPlugSDK. We provide methods to control each. Also you can enable and disable all beacons with a single command

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


###Public Properties
    assitanceRefreshInterval
    virtualTagRefreshInterval
    smartNoteRefreshInterval
    AssitanceEnabled
    HeatmapEnabled
    SmartNoteEnabled
    BeaconInfoEnabled
    VirtualTagEnabled
    dataRefreshInterval


Delegate Methods
---------------------

###pathPlug:getAssistanceData:

Returns audio sign interaction information encapsulated in a Plug Data

    - (void)pathPlug:(id)pathPlug getAssistanceData:(id)data

###pathPlug:getHeatmapData:forBeacon:

Fired when Heatmap is active and region enter/exit action happens

    - (void)pathPlug:(id)pathPlug getHeatmapData:(id)data forBeacon:(id)beacon

###pathPlug:getSmartNoteData:

Fired when a beacon with smartnote object is seen

      - (void)pathPlug:(id)pathPlug getSmartNoteData:(id)data

###pathPlug:getVirtualtagData:

Returns virtual tag interaction information encapsulated in a Plug Data

    - (void)pathPlug:(id)pathPlug getVirtualtagData:(id)data


###pathPlug:isFrameworkReady:

Fired when data is completely downloaded from API and ready to use

    - (void)pathPlug:(id)pathPlug isFrameworkReady:(id)result

###pathPlug:updatedBeaconData:andDistance:

Returns real time sightings of Beacons and their distances

    - (void)pathPlug:(id)pathPlug updatedBeaconData:(id)beacon andDistance:(id)distance
	

##Treasurehunt Manager
We gave Treasurehunt it's own manager to handle different contests and steps more effectively.
You can access it via

	[PathPlug sharedPlug] treasureHuntManager];
	
###Treasurehunt Delegates
Checks if we ranged a beacon for current question

	-(void)treasureHuntManager:(TreasureHuntManager*)manager didRangeBeacon:(Beacon*)beacon;
Checks if we received award code from PathPlug Server

	-(void)treasureHuntManager:(TreasureHuntManager *)manager didReceiveAwardCode:(NSString*)awardCode;
	
###Service Methods
####Initialize Methods 
You can set a random contest from ones defined our our backend. We advise you to define two or more sets for each contest to keep your users engaged further

	-(void)setRandomContest;

Control functions

	-(void)startTreasureHunt;

	-(void)stopTreasureHunt;
	
	-(void)resetTreasureHunt;

You can also start and stop ranging of beacons (if you need)

	-(void)startRanging;

	-(void)stopRanging;

Step Controllers

	-(void)moveToNextStep;

	-(void)failStep;
	
	-(void)successStep;
	
	-(void)goToFinalStep;

You can get info on current step for UI and other information

	-(TreasureHuntStep*)getCurrentStepInfo;
Return information about current contest

	-(TreasureHuntContest*)getCurrentContest;
Total Steps (For counters or page indicators)

	-(int)totalSteps;
Checks if given beacon is active (advanced)

	-(BOOL)checkForActiveBeacon:(Beacon*)beacon;


Class Documents
---------------------

You can access class documents for PathPlug [here](http://www.pathplug.com/public/documentation/ios/index.html)


## Author

Berk Taner, berk@pathplug.com

## License

PathPlug is available under the MIT license. See the LICENSE file for more info.
