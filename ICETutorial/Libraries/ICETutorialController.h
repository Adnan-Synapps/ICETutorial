//
//  ICETutorialController.h
//  ICETutorial
//
//  Created by Patrick Trillsam on 25/03/13.
//  Copyright (c) 2014 https://github.com/icepat/ICETutorial. All rights reserved.
//

@import UIKit;
#import "ICETutorialPage.h"
#import "ICETutorialStyle.h"

#define TUTORIAL_LABEL_TEXT_COLOR               [UIColor whiteColor]
#define TUTORIAL_LABEL_HEIGHT                   45
#define TUTORIAL_TITLE_FONT                     [UIFont fontWithName:@"Helvetica-Bold" size:17.0f]
#define TUTORIAL_TITLE_LINES_NUMBER             1
#define TUTORIAL_TITLE_OFFSET                   180
#define TUTORIAL_SUB_TITLE_FONT                 [UIFont fontWithName:@"Helvetica" size:15.0f]
#define TUTORIAL_SUB_TITLE_LINES_NUMBER         2
#define TUTORIAL_SUB_TITLE_OFFSET               150

// Scrolling state.
typedef NS_OPTIONS(NSUInteger, ScrollingState) {
    ScrollingStateAuto      = 1 << 0,
    ScrollingStateManual    = 1 << 1,
    ScrollingStateLooping   = 1 << 2,
};

typedef void (^ButtonBlock)(UIButton *button);

@protocol ICETutorialControllerDelegate;
@interface ICETutorialController : UIViewController <UIScrollViewDelegate>

@property (nonatomic, assign) BOOL autoScrollEnabled;
@property (nonatomic, weak) id<ICETutorialControllerDelegate> delegate;

IBInspectable @property (nonatomic, assign) BOOL hideLeftButton;
IBInspectable @property (nonatomic, assign) BOOL hideRightButton;
IBInspectable @property (nonatomic, assign) BOOL hideGradientView;

IBInspectable @property (nonatomic, strong) UIColor* leftButtonTitleColor;
IBInspectable @property (nonatomic, strong) UIColor* rightButtonTitleColor;

IBInspectable @property (nonatomic, strong) UIColor* leftButtonBackgroundColor;
IBInspectable @property (nonatomic, strong) UIColor* rightButtonBackgroundColor;

IBInspectable @property (nonatomic, copy) NSString* overLayTitle;


// Inits.
- (instancetype)initWithPages:(NSArray *)pages;
- (instancetype)initWithPages:(NSArray *)pages
                     delegate:(id<ICETutorialControllerDelegate>)delegate;

// Pages management.
- (void)setPages:(NSArray*)pages;
- (NSUInteger)numberOfPages;

// Scrolling.
- (void)startScrolling;
- (void)stopScrolling;

// Left and Right button title and image handling
-(void)setLeftButtonTitle:(NSString *)title;
-(void)setRightButtonTitle:(NSString *)title;

-(void)setLeftButtonImage:(NSString *)name;
-(void)setRightButtonImage:(NSString *)name;


// State.
- (ScrollingState)getCurrentState;

@end

@protocol ICETutorialControllerDelegate <NSObject>

@optional
- (void)tutorialController:(ICETutorialController *)tutorialController scrollingFromPageIndex:(NSUInteger)fromIndex toPageIndex:(NSUInteger)toIndex;
- (void)tutorialControllerDidReachLastPage:(ICETutorialController *)tutorialController;
- (void)tutorialController:(ICETutorialController *)tutorialController didClickOnLeftButton:(UIButton *)sender;
- (void)tutorialController:(ICETutorialController *)tutorialController didClickOnRightButton:(UIButton *)sender;
@end
