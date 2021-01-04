//
//  DKSatelliteAPIClient.h
//  DyKnow
//
//  Created by Alex Billingsley on 12/13/12.
//  Copyright (c) 2012 DyKnow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AFNetworking/AFHTTPRequestOperationManager.h>
#import "AFHTTPRequestOperationManager+Mantle.h"
#import "AFHTTPRequestOperationManager+MantleAutoRetry.h"

@protocol DKCabraRuleInterface;
@class DKParticipantStatus;
@class DKAssessmentQuestion;

@interface DKSatelliteAPIClient : AFHTTPRequestOperationManager

@property (assign, nonatomic, readonly, getter=isAuthenticated) BOOL authenticated;
@property (strong, nonatomic, readwrite) NSString *accessToken;

- (id)initWithBaseURL:(NSURL *)url accessToken:(NSString *)accessToken;

- (void)setConnectionStartedBlock:(void (^)(void))block;
- (void)setConnectionErrorBlock:(void (^)(NSError *error))block;
- (void)setConnectionMessageBlock:(void (^)(NSString *message))block;
- (void)setConnectionSlowBlock:(void (^)(void))block;
- (void)setConnectionClosedBlock:(void (^)(void))block;
//- (void)setConnectionStateChangeBlock:(void (^)(connectionState state))block;
- (void)setConnectionReconnectingBlock:(void (^)(void))block;
- (void)setConnectionReconnectedBlock:(void (^)(void))block;
- (void)setConnectionReachabilityStatusChangeBlock:(void (^)(AFNetworkReachabilityStatus status))block;
- (void)stop;

///-------------------------------
/// @name Broadcasts API Methods
///-------------------------------

- (void)attachToBroadcastId:(NSString *)broadcastId
                    success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                    failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

///-------------------------------
/// @name Cabra API Methods
///-------------------------------

- (void)openCabra:(NSNumber *)cabraId
          success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
          failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void)enterCabra:(NSString *)cabraId
           success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
           failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void)leaveCabra:(NSString *)cabraId
           success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
           failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void)getCabraUsers:(NSString *)cabraId
              success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
              failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void)getCabraFrames:(NSString *)cabraId
                 limit:(NSNumber *)limit
                offset:(NSNumber *)offset
               success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
               failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void)addCabraFrame:(NSString *)cabraId
            cabraRule:(id <DKCabraRuleInterface>)cabraRule
              payload:(NSDictionary *)payload
       conversationId:(NSString *)conversationId
              success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
              failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void)getCabraState:(NSString *)cabraId
              success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
              failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

///-------------------------------
/// @name Thumbnail APIs
///-------------------------------

- (void)thumbnailResponse:(NSString *)cabraId
                cabraRule:(id <DKCabraRuleInterface>)cabraRule
           conversationId:(NSString *)conversationId
                 location:(NSString *)url
                imageData:(NSData *)data
              contentType:(NSString *)mimeType
                   source:(NSString *)source
                  success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                  failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

///-------------------------------
/// @name Participant Activity APIs
///-------------------------------

- (void)participantActivityUpdate:(NSString *)cabraId
                        cabraRule:(id <DKCabraRuleInterface>)cabraRule
                   conversationId:(NSString *)conversationId
                  applicationName:(NSString *)name
                 bundleIdentifier:(NSString *)bundleIdentifier
                              url:(NSURL *)url
                            title:(NSString *)title
                            blocked:(NSString *)blocked
                          success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                          failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

///-------------------------------
/// @name Participant Status APIs
///-------------------------------

- (void)participantStatusRequest:(NSString *)cabraId
                       cabraRule:(id <DKCabraRuleInterface>)cabraRule
                  conversationId:(NSString *)conversationId
                   statusOptions:(NSArray *)statuses
                         success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                         failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void)participantStatusResponse:(NSString *)cabraId
                        cabraRule:(id <DKCabraRuleInterface>)cabraRule
                   conversationId:(NSString *)conversationId
                           status:(DKParticipantStatus *)status
                          success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                          failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

///-------------------------------
/// @name Assessment APIs
///-------------------------------

- (void)assessmentRequest:(NSString *)cabraId
                cabraRule:(id <DKCabraRuleInterface>)cabraRule
           conversationId:(NSString *)conversationId
                 question:(DKAssessmentQuestion *)question
                  success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                  failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void)assessmentResponse:(NSString *)cabraId
                 cabraRule:(id <DKCabraRuleInterface>)cabraRule
            conversationId:(NSString *)conversationId
                    answer:(NSString *)answer
                   success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                   failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

///-------------------------------
/// @name Messages APIs
///-------------------------------

- (void)messageAcknowledgement:(NSString *)cabraId
                     cabraRule:(id <DKCabraRuleInterface>)cabraRule
                conversationId:(NSString *)conversationId
           acknowledgementType:(NSString *)type
                       success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                       failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;
@end

extern NSString * const kDKSatelliteReceivedError;
