//
//  LRErrors.h
//  LoginRadiusSDK
//
//  Copyright © 2016 LoginRadius Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LRErrorCode.h"
/**
 *  Wrapper class for error objects
 */
@interface LRErrors : NSObject

#pragma mark - User Registration Service
+ (NSError*)serviceCancelled:(NSString*)action;
+ (NSError*)userRegistrationFailed;
+ (NSError*)userLoginFailed;
+ (NSError*)userForgotPasswordFailed;
+ (NSError*)userEmailVerificationFailed;
+ (NSError*)userSocialLoginFailed;
+ (NSError*)userResetPasswordFailed;

#pragma mark - User profile
+ (NSError*)tokenEmpty;
+ (NSError*)userProfieWithErrorCode:(NSString*)errorCode;
+ (NSError*)userProfileError;

#pragma mark - Social Login
+ (NSError *)socialLoginCancelled:(NSString*) provider;
+ (NSError *)socialLoginFailed:(NSString*) provider;

#pragma mark - Native Social Login
+ (NSError*)nativeTwitterLoginNoAccount;
+ (NSError*)nativeTwitterLoginCancelled;
+ (NSError*)nativeTwitterLoginFailed;
+ (NSError*)nativeFacebookLoginCancelled;
+ (NSError*)nativeFacebookLoginFailedMixedPermissions;
+ (NSError*)nativeFacebookLoginFailed;

#pragma mark - Touch ID
+ (NSError*)touchIDNotAvailable;
+ (NSError*)touchIDNotDeviceOwner;

@end
