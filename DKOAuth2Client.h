//
//  DKOAuth2Client.h
//  DyKnow
//
//  Created by Alex Billingsley on 4/25/12.
//  Copyright (c) 2012 DyKnow LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AFNetworking/AFHTTPRequestOperationManager.h>
#import "AFHTTPRequestOperationManager+Mantle.h"
#import "AFHTTPRequestOperationManager+MantleAutoRetry.h"

extern NSString * const kAFOAuthPasswordGrantType;
extern NSString * const kAFOAuthClientCredentialGrantType;
extern NSString * const kAFOAuthBasicGrantType;
extern NSString * const kAFOauthRefreshGrantType;

@interface DKOAuth2Client : AFHTTPRequestOperationManager

+ (DKOAuth2Client *)sharedClient;

- (void)authenticateUsingOAuthWithPath:(NSString *)path
                              username:(NSString *)username
                              password:(NSString *)password
                        clientUsername:(NSString *)clientUsername
                        clientPassword:(NSString *)clientPassword
                               success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                               failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void)authenticateUsingOAuthWithPath:(NSString *)path
                              username:(NSString *)username
                              password:(NSString *)password
                                vanity:(NSString *)vanity
                        clientUsername:(NSString *)clientUsername
                        clientPassword:(NSString *)clientPassword
                               success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                               failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void)authenticateUsingOAuthWithPath:(NSString *)path
                              username:(NSString *)username
                              password:(NSString *)password
                                vanity:(NSString *)vanity
                           accessToken:(NSString *)accessToken
                              hostname:(NSString *)hostname
                          macAddresses:(NSString *)macAddresses
                                osType:(NSString *)osType
                         osDescription:(NSString *)osDescription
                                domain:(NSString *)domain
                         clientVersion:(NSString *)version
                        clientUsername:(NSString *)clientUsername
                        clientPassword:(NSString *)clientPassword
                               success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                               failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void)authenticateUsingOAuthWithPath:(NSString *)path
                              username:(NSString *)username
                              password:(NSString *)password
                         customerToken:(NSString *)customerToken
                           accessToken:(NSString *)accessToken
                              hostname:(NSString *)hostname
                          macAddresses:(NSString *)macAddresses
                                osType:(NSString *)osType
                         osDescription:(NSString *)osDescription
                                domain:(NSString *)domain
                         clientVersion:(NSString *)version
                        clientUsername:(NSString *)clientUsername
                        clientPassword:(NSString *)clientPassword
                               success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                               failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void)authenticateUsingOAuthWithPath:(NSString *)path
                              clientId:(NSString *)clientId
                          clientSecret:(NSString *)clientSecret
                               success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
                               failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

@end
