/*
    File:  MUXSDKStats.h

	Framework:  MUXSDKStats

	Copyright © 2016 Mux, Inc. All rights reserved.
 */

/*!
	@class			MUXSDKStats

	@abstract
 MUXSDKStats offers an interface for monitoring video players.

	@discussion
 MUXSDKStats monitors an AVPlayer performance by sending tracking pings to Mux servers.

 In the simplest use case, an AVPlayer can be provided to the MUXSDKStats API and everything else is taken care of for you. The MUXSDKStats monitor methods attach a set of timed state and key-value observers on the AVPlayer. When you are done with an AVPlayer instance, call destroyPlayer: to remove the observers.

 If you change the video that is playing in an AVPlayer, you should call videoChangeForPlayer:withVideoData to provide the updated video information. Not calling videoChangeForPlayer:withVideoData when the video changes will cause tracking pings to be associated with the last video that was playing.
 */


#if __has_feature(modules)
@import Foundation;
@import AVKit;
@import AVFoundation;
@import MuxCore;
@import SystemConfiguration;
#else
#import <Foundation/Foundation.h>
#import <AVKit/AVKit.h>
#import <AVFoundation/AVFoundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#if TVOS
#import <MuxCore/MuxCoreTv.h>
#else
#import <MuxCore/MuxCore.h>
#endif
#endif
#import "MUXSDKPlayerBinding.h"

FOUNDATION_EXPORT
@interface MUXSDKStats : NSObject

- (_Null_unspecified instancetype)init NS_UNAVAILABLE;
+ (_Null_unspecified instancetype)new NS_UNAVAILABLE;

/*!
 @method      monitorAVPlayerViewController:withPlayerName:customerData:
 @abstract    Starts to monitor a given AVPlayerViewController.
 @param       player An AVPlayer to monitor
 @param       name A name for this instance of the player
 @param       videoR Bounding rectangle of the video
 @param       viewR Rectangle the video is being displayed within
 @param       customerData A MUXSDKCustomerData object with player, video, and view metadata
 @return      an instance of MUXSDKAVPlayerLayerBinding or null
 @discussion  Use this method to start a Mux player monitor on the given AVPlayerViewController. The player must have a name which is globally unique. The config provided should match the specifications in the Mux docs at https://docs.mux.com
 */
+ (MUXSDKPlayerBinding *_Nullable)monitorAVPlayer:(nonnull AVPlayer *)player
                                   withPlayerName:(nonnull NSString *)name
                                      videoBounds:(CGRect)videoR
                                       viewBounds:(CGRect)viewR
                                    customerData:(nonnull MUXSDKCustomerData *)customerData;
/*!
 @method      monitorAVPlayerViewController:withPlayerName:customerData:
 @abstract    Starts to monitor a given AVPlayerViewController.
 @param       player An AVPlayerViewController to monitor
 @param       name A name for this instance of the player
 @param       customerData A MUXSDKCustomerData object with player, video, and view metadata
 @return      an instance of MUXSDKAVPlayerLayerBinding or null
 @discussion  Use this method to start a Mux player monitor on the given AVPlayerViewController. The player must have a name which is globally unique. The config provided should match the specifications in the Mux docs at https://docs.mux.com
 */
+ (MUXSDKPlayerBinding *_Nullable)monitorAVPlayerViewController:(nonnull AVPlayerViewController *)player
                                                 withPlayerName:(nonnull NSString *)name
                                                   customerData:(nonnull MUXSDKCustomerData *)customerData;

/*!
 @method      monitorAVPlayerViewController:withPlayerName:customerData:automaticErrorTracking:
 @abstract    Starts to monitor a given AVPlayerViewController.
 @param       player An AVPlayerViewController to monitor
 @param       name A name for this instance of the player
 @param       customerData A MUXSDKCustomerData object with player, video, and view metadata
 @param       automaticErrorTracking boolean to indicate if the SDK should automatically track player errors
 @return      an instance of MUXSDKAVPlayerLayerBinding or null
 @discussion  Use this method to start a Mux player monitor on the given AVPlayerViewController. The player must have a name which is globally unique. The config provided should match the specifications in the Mux docs at https://docs.mux.com
 */
+ (MUXSDKPlayerBinding *_Nullable)monitorAVPlayerViewController:(nonnull AVPlayerViewController *)player
                                                 withPlayerName:(nonnull NSString *)name
                                                   customerData:(nonnull MUXSDKCustomerData *)customerData
                                         automaticErrorTracking:(BOOL)automaticErrorTracking;

/*!
 @method      monitorAVPlayerViewController:withPlayerName:customerData:automaticErrorTracking:
 @abstract    Starts to monitor a given AVPlayerViewController.
 @param       player An AVPlayerViewController to monitor
 @param       name A name for this instance of the player
 @param       customerData A MUXSDKCustomerData object with player, video, and view metadata
 @param       automaticErrorTracking boolean to indicate if the SDK should automatically track player errors
 @param       domain Domain to send tracking data to, if you want to use a custom beacon domain. Optional.
 @return      an instance of MUXSDKAVPlayerLayerBinding or null
 @discussion  Use this method to start a Mux player monitor on the given AVPlayerViewController. The player must have a name which is globally unique. The config provided should match the specifications in the Mux docs at https://docs.mux.com
 */
+ (MUXSDKPlayerBinding *_Nullable)monitorAVPlayerViewController:(nonnull AVPlayerViewController *)player
                                                 withPlayerName:(nonnull NSString *)name
                                                   customerData:(nonnull MUXSDKCustomerData *)customerData
                                         automaticErrorTracking:(BOOL)automaticErrorTracking
                                                   beaconDomain:(nullable NSString *)domain;

/*!
 @method      monitorAVPlayerViewController:withPlayerName:playerData:videoData:
 @abstract    Starts to monitor a given AVPlayerViewController.
 @param       player An AVPlayerViewController to monitor
 @param       name A name for this instance of the player
 @param       playerData A MUXSDKCustomerPlayerData object with player metadata
 @param       videoData A MUXSDKCustomerVideoData object with video metadata
 @return      an instance of MUXSDKAVPlayerLayerBinding or null
 @discussion  Use this method to start a Mux player monitor on the given AVPlayerViewController. The player must have a name which is globally unique. The config provided should match the specifications in the Mux docs at https://docs.mux.com
 */
+ (MUXSDKPlayerBinding *_Nullable)monitorAVPlayerViewController:(nonnull AVPlayerViewController *)player withPlayerName:(nonnull NSString *)name playerData:(nonnull MUXSDKCustomerPlayerData *)playerData videoData:(nullable MUXSDKCustomerVideoData *)videoData __attribute__((deprecated("Please migrate to monitorAVPlayerViewController:withPlayerName:customerData:")));

/*!
 @method      monitorAVPlayerViewController:withPlayerName:playerData:videoData:viewData:
 @abstract    Starts to monitor a given AVPlayerViewController.
 @param       player An AVPlayerViewController to monitor
 @param       name A name for this instance of the player
 @param       playerData A MUXSDKCustomerPlayerData object with player metadata
 @param       videoData A MUXSDKCustomerVideoData object with video metadata
 @param       viewData A MUXSDKCustomerViewData object with view metadata
 @return      an instance of MUXSDKAVPlayerLayerBinding or null
 @discussion  Use this method to start a Mux player monitor on the given AVPlayerViewController. The player must have a name which is globally unique. The config provided should match the specifications in the Mux docs at https://docs.mux.com
 */
+ (MUXSDKPlayerBinding *_Nullable)monitorAVPlayerViewController:(nonnull AVPlayerViewController *)player withPlayerName:(nonnull NSString *)name playerData:(nonnull MUXSDKCustomerPlayerData *)playerData videoData:(nullable MUXSDKCustomerVideoData *)videoData viewData: (nullable MUXSDKCustomerViewData *) viewData __attribute__((deprecated("Please migrate to monitorAVPlayerViewController:withPlayerName:customerData:")));

/*!
 @method      monitorAVPlayerViewController:withPlayerName:playerData:videoData:automaticErrorTracking:
 @abstract    Starts to monitor a given AVPlayerViewController.
 @param       player An AVPlayerViewController to monitor
 @param       name A name for this instance of the player
 @param       playerData A MUXSDKCustomerPlayerData object with player metadata
 @param       videoData A MUXSDKCustomerVideoData object with video metadata
 @param       automaticErrorTracking boolean to indicate if the SDK should automatically track player errors
 @return      an instance of MUXSDKAVPlayerLayerBinding or null
 @discussion  Use this method to start a Mux player monitor on the given AVPlayerViewController. The player must have a name which is globally unique. The config provided should match the specifications in the Mux docs at https://docs.mux.com
 */
+ (MUXSDKPlayerBinding *_Nullable)monitorAVPlayerViewController:(nonnull AVPlayerViewController *)player withPlayerName:(nonnull NSString *)name playerData:(nonnull MUXSDKCustomerPlayerData *)playerData videoData:(nullable MUXSDKCustomerVideoData *)videoData automaticErrorTracking:(BOOL)automaticErrorTracking __attribute__((deprecated("Please migrate to monitorAVPlayerViewController:withPlayerName:customerData:automaticErrorTracking:")));
/*!
 @method      monitorAVPlayerViewController:withPlayerName:playerData:videoData:viewData:automaticErrorTracking:
 @abstract    Starts to monitor a given AVPlayerViewController.
 @param       player An AVPlayerViewController to monitor
 @param       name A name for this instance of the player
 @param       playerData A MUXSDKCustomerPlayerData object with player metadata
 @param       videoData A MUXSDKCustomerVideoData object with video metadata
 @param       viewData A MUXSDKCustomerViewData object with view metadata
 @param       automaticErrorTracking boolean to indicate if the SDK should automatically track player errors
 @return      an instance of MUXSDKAVPlayerLayerBinding or null
 @discussion  Use this method to start a Mux player monitor on the given AVPlayerViewController. The player must have a name which is globally unique. The config provided should match the specifications in the Mux docs at https://docs.mux.com
 */
+ (MUXSDKPlayerBinding *_Nullable)monitorAVPlayerViewController:(nonnull AVPlayerViewController *)player withPlayerName:(nonnull NSString *)name playerData:(nonnull MUXSDKCustomerPlayerData *)playerData videoData:(nullable MUXSDKCustomerVideoData *)videoData viewData: (nullable MUXSDKCustomerViewData *) viewData automaticErrorTracking:(BOOL)automaticErrorTracking __attribute__((deprecated("Please migrate to monitorAVPlayerViewController:withPlayerName:customerData:automaticErrorTracking:")));

/*!
 @method      updateAVPlayerViewController:withPlayerName
 @abstract    Updates the monitor for a player to a new AVPlayerViewController.
 @param       player The new AVPlayerViewController to monitor
 @param       name The name of the player instance to update
 @discussion  Use this method to change which AVPlayerViewController a Mux player monitor is watching. The player monitor must previously have been created via a monitorAVPlayerViewController call.
 */
+ (void)updateAVPlayerViewController:(nonnull AVPlayerViewController *)player withPlayerName:(nonnull NSString *)name;


/*!
 @method      monitorAVPlayerLayer:withPlayerName:customerData:
 @abstract    Starts to monitor a given AVPlayerLayer.
 @param       player An AVPlayerLayer to monitor
 @param       name A name for this instance of the player
 @param       customerData A MUXSDKCustomerData object with player, video, and view metadata
 @return      an instance of MUXSDKAVPlayerLayerBinding or null
 @discussion  Use this method to start a Mux player monitor on the given AVPlayerLayer. The player must have a name which is globally unique. The config provided should match the specifications in the Mux docs at https://docs.mux.com
 */
+ (MUXSDKPlayerBinding *_Nullable)monitorAVPlayerLayer:(nonnull AVPlayerLayer *)player
                                        withPlayerName:(nonnull NSString *)name
                                          customerData:(nonnull MUXSDKCustomerData *)customerData;

/*!
 @method      monitorAVPlayerLayer:withPlayerName:customerData:automaticErrorTracking:
 @abstract    Starts to monitor a given AVPlayerLayer.
 @param       player An AVPlayerLayer to monitor
 @param       name A name for this instance of the player
 @param       customerData A MUXSDKCustomerData object with player, video, and view metadata
 @param       automaticErrorTracking boolean to indicate if the SDK should automatically track player errors
 @return      an instance of MUXSDKAVPlayerLayerBinding or null
 @discussion  Use this method to start a Mux player monitor on the given AVPlayerLayer. The player must have a name which is globally unique. The config provided should match the specifications in the Mux docs at https://docs.mux.com
 */
+ (MUXSDKPlayerBinding *_Nullable)monitorAVPlayerLayer:(nonnull AVPlayerLayer *)player
                                        withPlayerName:(nonnull NSString *)name
                                          customerData:(nonnull MUXSDKCustomerData *)customerData
                                automaticErrorTracking:(BOOL)automaticErrorTracking;
/*!
 @method      monitorAVPlayerLayer:withPlayerName:customerData:automaticErrorTracking:
 @abstract    Starts to monitor a given AVPlayerLayer.
 @param       player An AVPlayerLayer to monitor
 @param       name A name for this instance of the player
 @param       customerData A MUXSDKCustomerData object with player, video, and view metadata
 @param       automaticErrorTracking boolean to indicate if the SDK should automatically track player errors
 @param       domain Domain to send tracking data to, if you want to use a custom beacon domain. Optional.
 @return      an instance of MUXSDKAVPlayerLayerBinding or null
 @discussion  Use this method to start a Mux player monitor on the given AVPlayerLayer. The player must have a name which is globally unique. The config provided should match the specifications in the Mux docs at https://docs.mux.com
 */
+ (MUXSDKPlayerBinding *_Nullable)monitorAVPlayerLayer:(nonnull AVPlayerLayer *)player
                                        withPlayerName:(nonnull NSString *)name
                                          customerData:(nonnull MUXSDKCustomerData *)customerData
                                automaticErrorTracking:(BOOL)automaticErrorTracking
                                          beaconDomain:(nullable NSString *)domain;


/*!
 @method      monitorAVPlayerLayer:withPlayerName:playerData:videoData:
 @abstract    Starts to monitor a given AVPlayerLayer.
 @param       player An AVPlayerLayer to monitor
 @param       name A name for this instance of the player
 @param       playerData A MUXSDKCustomerPlayerData object with player metadata
 @param       videoData A MUXSDKCustomerVideoData object with video metadata
 @return      an instance of MUXSDKAVPlayerLayerBinding or null
 @discussion  Use this method to start a Mux player monitor on the given AVPlayerLayer. The player must have a name which is globally unique. The config provided should match the specifications in the Mux docs at https://docs.mux.com
 */
+ (MUXSDKPlayerBinding *_Nullable)monitorAVPlayerLayer:(nonnull AVPlayerLayer *)player withPlayerName:(nonnull NSString *)name playerData:(nonnull MUXSDKCustomerPlayerData *)playerData videoData:(nullable MUXSDKCustomerVideoData *)videoData __attribute__((deprecated("Please migrate to monitorAVPlayerLayer:withPlayerName:customerData:")));


/*!
 @method      monitorAVPlayerLayer:withPlayerName:playerData:videoData:viewData:
 @abstract    Starts to monitor a given AVPlayerLayer.
 @param       player An AVPlayerLayer to monitor
 @param       name A name for this instance of the player
 @param       playerData A MUXSDKCustomerPlayerData object with player metadata
 @param       videoData A MUXSDKCustomerVideoData object with video metadata
 @param       viewData A MUXSDKCustomerViewData object with view metadata
 @return      an instance of MUXSDKAVPlayerLayerBinding or null
 @discussion  Use this method to start a Mux player monitor on the given AVPlayerLayer. The player must have a name which is globally unique. The config provided should match the specifications in the Mux docs at https://docs.mux.com
 */
+ (MUXSDKPlayerBinding *_Nullable)monitorAVPlayerLayer:(nonnull AVPlayerLayer *)player withPlayerName:(nonnull NSString *)name playerData:(nonnull MUXSDKCustomerPlayerData *)playerData videoData:(nullable MUXSDKCustomerVideoData *)videoData viewData: (nullable MUXSDKCustomerViewData *) viewData __attribute__((deprecated("Please migrate to monitorAVPlayerLayer:withPlayerName:customerData:")));


/*!
 @method      monitorAVPlayerLayer:withPlayerName:playerData:videoData:automaticErrorTracking:
 @abstract    Starts to monitor a given AVPlayerLayer.
 @param       player An AVPlayerLayer to monitor
 @param       name A name for this instance of the player
 @param       playerData A MUXSDKCustomerPlayerData object with player metadata
 @param       videoData A MUXSDKCustomerVideoData object with video metadata
 @param       automaticErrorTracking boolean to indicate if the SDK should automatically track player errors
 @return      an instance of MUXSDKAVPlayerLayerBinding or null
 @discussion  Use this method to start a Mux player monitor on the given AVPlayerLayer. The player must have a name which is globally unique. The config provided should match the specifications in the Mux docs at https://docs.mux.com
 */
+ (MUXSDKPlayerBinding *_Nullable)monitorAVPlayerLayer:(nonnull AVPlayerLayer *)player withPlayerName:(nonnull NSString *)name playerData:(nonnull MUXSDKCustomerPlayerData *)playerData videoData:(nullable MUXSDKCustomerVideoData *)videoData automaticErrorTracking:(BOOL)automaticErrorTracking __attribute__((deprecated("Please migrate to monitorAVPlayerLayer:withPlayerName:customerData:automaticErrorTracking:")));

/*!
 @method      monitorAVPlayerLayer:withPlayerName:playerData:videoData:viewData:automaticErrorTracking:
 @abstract    Starts to monitor a given AVPlayerLayer.
 @param       player An AVPlayerLayer to monitor
 @param       name A name for this instance of the player
 @param       playerData A MUXSDKCustomerPlayerData object with player metadata
 @param       videoData A MUXSDKCustomerVideoData object with video metadata
 @param       viewData A MUXSDKCustomerViewData object with view metadata
 @param       automaticErrorTracking boolean to indicate if the SDK should automatically track player errors
 @return      an instance of MUXSDKAVPlayerLayerBinding or null
 @discussion  Use this method to start a Mux player monitor on the given AVPlayerLayer. The player must have a name which is globally unique. The config provided should match the specifications in the Mux docs at https://docs.mux.com
 */
+ (MUXSDKPlayerBinding *_Nullable)monitorAVPlayerLayer:(nonnull AVPlayerLayer *)player withPlayerName:(nonnull NSString *)name playerData:(nonnull MUXSDKCustomerPlayerData *)playerData videoData:(nullable MUXSDKCustomerVideoData *)videoData viewData: (nullable MUXSDKCustomerViewData *) viewData automaticErrorTracking:(BOOL)automaticErrorTracking __attribute__((deprecated("Please migrate to monitorAVPlayerLayer:withPlayerName:customerData:automaticErrorTracking:")));


/*!
 @method      updateAVPlayerLayer:withPlayerName:
 @abstract    Updates the monitor for a player to a new AVPlayerLayer.
 @param       player The new AVPlayerLayer to monitor
 @param       name The name of the player instance to update
 @discussion  Use this method to change which AVPlayerLayer a Mux player monitor is watching. The player monitor must previously have been created via a monitorAVPlayerLayer call.
 */
+ (void)updateAVPlayerLayer:(nonnull AVPlayerLayer *)player withPlayerName:(nonnull NSString *)name;

/*!
 @method			destroyPlayer:
 @abstract    Removes any AVPlayer observers on the associated player.
 @param       name The name of the player to destory
 @discussion  When you are done with a player, call destoryPlayer: to remove all observers that were set up when monitorPlayer:withPlayerName:andConfig: was called and to ensure that any remaining tracking pings are sent to complete the view. If the name of the player provided was not previously initialized, an exception will be raised.
 */
+ (void)destroyPlayer:(nonnull NSString *)name;

/*!
 @method      setAutomaticVideoChange:forPlayer:enabled
 @abstract    Allows default videochange functionality to be disabled.
 @param       name The name of the player to update
 @discussion  Use this method to disable built in videochange calls when using AVQueuePlayer. The player name provided must been passed as the name in a monitorPlayer:withPlayerName:andConfig: call. The config provided should match the specifications in the Mux docs at https://docs.mux.com and should set the enabled value to false. The default setting is true.

 */
+ (void)setAutomaticVideoChange:(nonnull NSString *)name enabled:(Boolean)enabled;

/*!
 @method      videoChangeForPlayer:withCustomerData:
 @abstract    Signals that a player is now playing a different video.
 @param       name The name of the player to update
 @param       customerData A MUXSDKCustomerData object with player, video, and view metadata
 @discussion  Use this method to signal that the player is now playing a new video. The player name provided must been passed as the name in a monitorPlayer:withPlayerName:andConfig: call. The config provided should match the specifications in the Mux docs at https://docs.mux.com and should include all desired keys, not just those keys that are specific to this video. If the name of the player provided was not previously initialized, an exception will be raised.

 */
+ (void)videoChangeForPlayer:(nonnull NSString *)name
            withCustomerData:(nullable MUXSDKCustomerData *)customerData;

/*!
 @method      videoChangeForPlayer:withVideoData:
 @abstract    Signals that a player is now playing a different video.
 @param       name The name of the player to update
 @param       videoData A MUXSDKCustomerVideoData object with video metadata
 @discussion  Use this method to signal that the player is now playing a new video. The player name provided must been passed as the name in a monitorPlayer:withPlayerName:andConfig: call. The config provided should match the specifications in the Mux docs at https://docs.mux.com and should include all desired keys, not just those keys that are specific to this video. If the name of the player provided was not previously initialized, an exception will be raised.

 */
+ (void)videoChangeForPlayer:(nonnull NSString *)name
               withVideoData:(nullable MUXSDKCustomerVideoData *)videoData __attribute__((deprecated("Please migrate to videoChangeForPlayer:withCustomerData:")));

/*!
 @method      videoChangeForPlayer:withPlayerData:withVideoData
 @abstract    Signals that a player is now playing a different video.
 @param       name The name of the player to update
 @param       playerData A MUXSDKCustomerPlayerData object with video metadata
 @param       videoData A MUXSDKCustomerVideoData object with video metadata
 @discussion  Use this method to signal that the player is now playing a new video. The player name provided must been passed as the name in a monitorPlayer:withPlayerName:andConfig: call. The config provided should match the specifications in the Mux docs at https://docs.mux.com and should include all desired keys, not just those keys that are specific to this video. If the name of the player provided was not previously initialized, an exception will be raised.

 */
+ (void)videoChangeForPlayer:(nonnull NSString *)name
              withPlayerData:(nullable MUXSDKCustomerPlayerData *)playerData
               withVideoData:(nullable MUXSDKCustomerVideoData *)videoData __attribute__((deprecated("Please migrate to videoChangeForPlayer:withCustomerData:")));

/*!
 @method      videoChangeForPlayer:withPlayerData:withVideoData:viewData:
 @abstract    Signals that a player is now playing a different video.
 @param       name The name of the player to update
 @param       playerData A MUXSDKCustomerPlayerData object with video metadata
 @param       videoData A MUXSDKCustomerVideoData object with video metadata
 @param       viewData A MUXSDKCustomerViewData object with view metadata
 @discussion  Use this method to signal that the player is now playing a new video. The player name provided must been passed as the name in a monitorPlayer:withPlayerName:andConfig: call. The config provided should match the specifications in the Mux docs at https://docs.mux.com and should include all desired keys, not just those keys that are specific to this video. If the name of the player provided was not previously initialized, an exception will be raised.

 */
+ (void)videoChangeForPlayer:(nonnull NSString *)name
              withPlayerData:(nullable MUXSDKCustomerPlayerData *)playerData
               withVideoData:(nullable MUXSDKCustomerVideoData *)videoData
                    viewData:(nullable MUXSDKCustomerViewData *)viewData __attribute__((deprecated("Please migrate to videoChangeForPlayer:withCustomerData:")));

/*!
 @method      programChangeForPlayer:withCustomerData:
 @abstract    Signals that a player is now playing a different video of a playlist; or a different program of a live stream
 @param       name The name of the player to update
 @param       customerData A MUXSDKCustomerData object with player, video, and view metadata
 @discussion  Use this method to signal that the player is now playing a differnt video of a playlist, or a different program of a live stream. The player name provided must been passed as the name in a monitorPlayer:withPlayerName:andConfig: call. The config provided should match the specifications in the Mux docs at https://docs.mux.com and should include all desired keys, not just those keys that are specific to this video. If the name of the player provided was not previously initialized, an exception will be raised.
 */
+ (void)programChangeForPlayer:(nonnull NSString *)name
              withCustomerData:(nullable MUXSDKCustomerData *)customerData;

/*!
 @method      programChangeForPlayer:withVideoData:
 @abstract    Signals that a player is now playing a different video of a playlist; or a different program of a live stream
 @param       name The name of the player to update
 @param       videoData A MUXSDKCustomerVideoData object with video metadata
 @discussion  Use this method to signal that the player is now playing a differnt video of a playlist, or a different program of a live stream. The player name provided must been passed as the name in a monitorPlayer:withPlayerName:andConfig: call. The config provided should match the specifications in the Mux docs at https://docs.mux.com and should include all desired keys, not just those keys that are specific to this video. If the name of the player provided was not previously initialized, an exception will be raised.
 */
+ (void)programChangeForPlayer:(nonnull NSString *)name
                 withVideoData:(nullable MUXSDKCustomerVideoData *)videoData __attribute__((deprecated("Please migrate to programChangeForPlayer:withCustomerData:")));

/*!
 @method      setCustomerData:forPlayer:
 @abstract    allows customerData to be set or updated for the player
 @param       name The name of the player to update
 @param       customerData A MUXSDKCustomerData object with player, video, and view metadata
 @discussion  Use this method after you have already initialized the Mux SDK at any time before the player has been destroyed.
 */
+ (void)setCustomerData:(nullable MUXSDKCustomerData *)customerData forPlayer:(nonnull NSString *)name;

/*!
 @method      updateCustomerData:forPlayer:withPlayerData:withVideoData
 @abstract    allows videoData to be set or updated for the player
 @param       name The name of the player to update
 @param       playerData A MUXSDKCustomerPlayerData object with player metadata
 @param       videoData A MUXSDKCustomerVideoData object with video metadata
 @discussion  Use this method after you have already initialized the Mux SDK at any time before the player has been destroyed. Pass in either videoData or playerData.
 */
+ (void)updateCustomerDataForPlayer:(nonnull NSString *)name withPlayerData:(nullable MUXSDKCustomerPlayerData *)playerData withVideoData:(nullable MUXSDKCustomerVideoData *)videoData __attribute__((deprecated("Please migrate to setCustomerData:forPlayer:")));

/*!
 @method      updateCustomerData:forPlayer:withPlayerData:withVideoData:viewData:
 @abstract    allows videoData to be set or updated for the player
 @param       name The name of the player to update
 @param       playerData A MUXSDKCustomerPlayerData object with video metadata
 @param       videoData A MUXSDKCustomerVideoData object with video metadata
 @param       viewData A MUXSDKCustomerViewData object with view metadata
 @discussion  Use this method after you have already initialized the Mux SDK at any time before the player has been destroyed. Pass in either videoData, playerData, or viewData.
 */
+ (void)updateCustomerDataForPlayer:(nonnull NSString *)name withPlayerData:(nullable MUXSDKCustomerPlayerData *)playerData withVideoData:(nullable MUXSDKCustomerVideoData *)videoData viewData: (nullable MUXSDKCustomerViewData *) viewData __attribute__((deprecated("Please migrate to setCustomerData:forPlayer:")));


/*!
@method      orientationChangeForPlayer:withOrientation:
@abstract    Notifies the Mux SDK that the view's orientation has changed.
@param       name The name of the player to update
@param       orientation A MUXSDKViewOrientation enum value representing if the view has changed to portrait or landscape
*/
+ (void) orientationChangeForPlayer:(nonnull NSString *) name  withOrientation:(MUXSDKViewOrientation) orientation;

/*!
@method      dispatchError:withMessage:forPlayer
@abstract    Dispatches an error with the specified error code and message for the given player
@param       code The error code in string format
@param       message The error message in string format
@param       name The name of the player
*/
+ (void)dispatchError:(nonnull NSString *)code withMessage:(nonnull NSString *)message forPlayer:(nonnull NSString *)name;

@end
