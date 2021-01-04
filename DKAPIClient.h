//
//  DKAPIClient.h
//  DyKnow
//
//  Created by Alex Billingsley on 11/1/12.
//  Copyright (c) 2012 DyKnow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AFNetworking/AFHTTPRequestOperationManager.h>
#import "AFHTTPRequestOperationManager+Mantle.h"
#import "AFHTTPRequestOperationManager+MantleAutoRetry.h"

@interface DKAPIClient : AFHTTPRequestOperationManager

@property (assign, nonatomic, readonly, getter=isAuthenticated) BOOL authenticated;
@property (strong, nonatomic, readwrite) NSString *accessToken;
@property (nonatomic, readonly) BOOL processingReset;
@property (nonatomic, readonly) BOOL processingDelay;

+ (DKAPIClient *)sharedClient;

- (void)signout;

///-------------------------------
/// @name Monitor API
///-------------------------------

- (void)getMonitorInstructions;
- (void)setConnectionStartedBlock:(void (^)(void))block;
- (void)setConnectionErrorBlock:(void (^)(NSError *error))block;
- (void)setConnectionMessageBlock:(void (^)(NSString *message))block;
- (void)setConnectionSlowBlock:(void (^)(void))block;
- (void)setConnectionClosedBlock:(void (^)(void))block;
//- (void)setConnectionStateChangeBlock:(void (^)(connectionState state))block;
- (void)setConnectionReconnectingBlock:(void (^)(void))block;
- (void)setConnectionReconnectedBlock:(void (^)(void))block;
- (void)setConnectionReachabilityStatusChangeBlock:(void (^)(AFNetworkReachabilityStatus status))block;
- (BOOL)trySetAccessToken:(NSString *)accessToken;

- (void)stop;

extern NSString * const kDKMonitorRealtimeJoin;
extern NSString * const kDKMonitorRealtimeSteal;
extern NSString * const kDKMonitorRealtimeLeave;

///-------------------------------
/// @name Settings API
///-------------------------------

- (void)getSettingsWithSuccess:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                       failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void)getSettingsWithLimit:(NSNumber *)limit
                      offset:(NSNumber *)offset
                     success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                     failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;


- (void)getSetting:(NSString *)setting
           success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
           failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

///-------------------------------
/// @name Users API
///-------------------------------

- (void)getUsersMeWithSuccess:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                      failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;


///-------------------------------
/// @name Devices API
///-------------------------------

- (void)updateDeviceWithUsername:(NSString *)username
                        hostname:(NSString *)hostname
                    macAddresses:(NSString *)macAddresses
                          osType:(NSString *)osType
                   osDescription:(NSString *)osDescription
                          domain:(NSString *)domain
                   clientVersion:(NSString *)version
                         success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                         failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;
@end
