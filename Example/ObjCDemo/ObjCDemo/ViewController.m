//
//  ViewController.m
//  ObjCDemo
//
//  Created by Raviteja Ghanta on 18/05/16.
//  Copyright © 2016 Raviteja Ghanta. All rights reserved.
//

#import "ViewController.h"
#import <LoginRadiusSDK/LoginRadius.h>
#import "DetailViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    // Check if already login
    NSUserDefaults *lrUser = [NSUserDefaults standardUserDefaults];
    NSInteger profile =  [lrUser integerForKey:@"isLoggedIn"];
    if (profile) {
            [self performSegueWithIdentifier:@"profile" sender:self];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)loginWithTwitter:(id)sender {
    [[LoginRadiusSocialLoginManager sharedInstance] loginWithProvider:@"twitter" inController:self completionHandler:^(BOOL success, NSError *error) {
        if (success) {
            NSLog(@"successfully logged in with twitter");
            [self showProfileController];
        } else {
            NSLog(@"Error: %@", [error description]);
        }
    }];
}

- (IBAction)loginWithFacebook:(id)sender {
    [[LoginRadiusSocialLoginManager sharedInstance] loginWithProvider:@"facebook" inController:self completionHandler:^(BOOL success, NSError *error) {
        if (success) {
            NSLog(@"successfully logged in with facebook");
            [self showProfileController];
        } else {
            NSLog(@"Error: %@", [error description]);
        }
    }];
}

- (IBAction)loginWithLinkedin:(id)sender {
    [[LoginRadiusSocialLoginManager sharedInstance] loginWithProvider:@"linkedin" inController:self completionHandler:^(BOOL success, NSError *error) {
        if (success) {
            NSLog(@"successfully logged in with linkedin");
            [self showProfileController];
        } else {
            NSLog(@"Error: %@", [error description]);
        }
    }];
}

- (IBAction)registerWithEmail:(id)sender {
    [[LoginRadiusRegistrationManager sharedInstance] authRegistrationWithData:@{
                                                                                @"Email": @[
                                                                                          @{
                                                                                              @"Type": @"Primary",
                                                                                              @"Value": @"test@gmail.com"
                                                                                          }
                                                                                          ],
                                                                                @"Password": @"password"
                                                                                }
                                                                     withSott:@"<your sott here>"
                                                              verificationUrl:@"<your verification url>"
                                                                emailTemplate:@""
                                                            completionHandler:^(NSDictionary *data, NSError *error) {
                                                                                    if (!error) {
                                                                                        // Registration only registers the user. Call login to set the session
                                                                                        NSLog(@"successfully reg %@", data);
                                                                                    } else {
                                                                                        NSLog(@"Error: %@", [error description]);
                                                                                    }
                                                                                }];
}

- (IBAction)loginWithEmail:(id)sender {
    [[LoginRadiusRegistrationManager sharedInstance] authLoginWithEmail:@"test@gmail.com"
                                                           withPassword:@"password"
                                                               loginUrl:@""
                                                        verificationUrl:@""
                                                          emailTemplate:@""
                                                      completionHandler:^(NSDictionary *data, NSError *error) {
                                                        if (!error) {
                                                            NSLog(@"successfully logged in %@", data);
                                                            [self showProfileController];
                                                        } else {
                                                            NSLog(@"Error: %@", [error description]);
                                                        }
                                                    }];
}

- (void) showProfileController {
    [self performSegueWithIdentifier:@"profile" sender:self];
}

@end
