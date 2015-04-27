//
//  Consts.h
//  Outliers
//
//  Created by Vadim on 3/2/14.
//  Copyright (c) 2014 Hiperware Pte Ltd. All rights reserved.
//

#ifndef Outliers_Consts_h
#define Outliers_Consts_h

// from here: https://developer.amazon.com/application/general/M1PAYM3QXSAEVO/detail.html?default
#define AMAZON_ASSOCIATES_API_KEY @"4d2c362ec48a4c8cb26f83635425db79"

// API errors
static const int E_API_FORBIDDEN    = 403;      // Authentication failed (wrong user id or password) OR access denied because of permissions;
static const int E_API_NOT_FOUND    = 404;      // Not found, e.g. when parent requests not existing child’s data;
static const int E_API_BAD_METHOD   = 405;      // Method not allowed (e.g. if you use POST instead of GET);
static const int E_API_SESSION      = 419;      // Session has expired or user not logged in;
static const int E_API_OTHER        = 500;      // Other errors;

static const int E_API_BAD_PARAM    = 1001;     // Bad parameter (invalid parameter has been passed to the API);
static const int E_API_IN_PROGRESS  = 1002;     // an api call already is in progress
static const int E_API_BAD_PATH     = 1003;

static const NSString *S_USER_NOT_LOGGED_IN = @"You're not logged in";
static const NSString *S_BAD_URL = @"Invalid URL argument!";
static const NSString *S_BAD_METHOD = @"Invalid HTTP method!";

// app errors
static const int E_ARG              = 2000;
static const int E_BAD_DATA         = 2001;
static const int E_BAD_NETWORK      = 2002;
static const int E_STORAGE          = 2003;
static const int E_APP              = 2004;
static const int E_ANSWER           = 2005;

static const CGFloat DIALOG_CORNER_RADIUS = 14.0f;


// achievement IDs (in backend code defined in schema/achievements.js)
static const NSUInteger ACHIEVEMENT_FASTEST_TIME        = 300;    // fastest answering time
static const NSUInteger ACHIEVEMENT_CORRECT_IN_ROW_5    = 400;    // 5 correct answers in a row
static const NSUInteger ACHIEVEMENT_CORRECT_IN_ROW_10   = 410;    // 10 correct answers in a row
static const NSUInteger ACHIEVEMENT_CORRECT_IN_ROW_20   = 420;    // 20 correct answers in a row
static const NSUInteger ACHIEVEMENT_CORRECT_IN_ROW_30   = 430;    // 30 correct answers in a row
static const NSUInteger ACHIEVEMENT_CORRECT_IN_ROW_40   = 440;    // 40 correct answers in a row
static const NSUInteger ACHIEVEMENT_CORRECT_IN_ROW_50   = 450;    // 50 correct answers in a row
static const NSUInteger ACHIEVEMENT_CORRECT_IN_ROW_60   = 460;    // 60 correct answers in a row
static const NSUInteger ACHIEVEMENT_CORRECT_IN_ROW_70   = 470;    // 70 correct answers in a row
static const NSUInteger ACHIEVEMENT_CORRECT_IN_ROW_80   = 480;    // 80 correct answers in a row
static const NSUInteger ACHIEVEMENT_CORRECT_IN_ROW_90   = 490;    // 90 correct answers in a row
static const NSUInteger ACHIEVEMENT_CORRECT_IN_ROW_100  = 499;    // 100 correct answers in a row

// achievement labels
static NSString *S_ACHIEVEMENT_FASTEST_TIME = @"Fastest answering time!";
static NSString *S_ACHIEVEMENT_CORRECT_IN_ROW = @"%d correct answers in row!";

// tab content sizes
static const CGFloat TAB_CONTENT_X = 20.0f;
static const CGFloat TAB_CONTENT_Y = 185.0f;
static const CGFloat TAB_CONTENT_W = 984.0f;
static const CGFloat TAB_CONTENT_H = 563.0f;

// used if there are no stats for the question
// this value should be the same, as in backend consts.js!
static const NSUInteger DEFAULT_ANSWER_TIME = 7;


static const NSString *S_BAD_NETWORK = @"Network not available";
static const NSString *S_BAD_IMAGE_ID = @"Bad image URL and name";

static const NSString *S_CANT_LOAD_QUESTION = @"Can't load question data!";
static const NSString *S_BAD_QUESTION = @"Bad question data!";
static const NSString *S_ANSWER_FILL_REQUIRED = @"Not all answer fields filled!";
static const NSString *S_ANSWER_SELECT_REQUIRED = @"Answer not selected!";


static const NSString *REACHABILITY_CHECK_ADDRESS = @"www.apple.com";

static const NSTimeInterval REQ_TIMEOUT = 20;

static const NSString *API_ADDRESS = @"https://outliers-v2.herokuapp.com";
//static const NSString *API_ADDRESS = @"http://192.168.1.40:8000";

// UI
static NSString *S_COINS = @"coins";

static NSString *S_START = @"Start!";
static NSString *S_CONTINUE = @"Continue!";
static NSString *S_CATCH_UP = @"Catch up!";

static NSString *S_INACTIVITY_TIMEOUT_MESSAGE = @"The app was inactive for a long time. Please login again.";

static NSString *S_NO_OBJECTIVES_FOUND = @"No objectives found. Ask parents to create one for you.";
static NSString *S_REDEMPTION_SUCCESSFUL = @"Success! Be patient and wait for your reward!\nAlso don't forget to select your next reward!";
static NSString *S_BAD_EMAIL = @"Invalid email";
static NSString *S_BAD_NAME_LENGTH = @"Invalid name";
static NSString *S_BAD_PASSWORD_LENGTH = @"Invalid password length";
static NSString *S_BAD_PASSWORDS = @"Passwords do not match";
static NSString *S_BAD_GRADE = @"Invalid grade";
static NSString *S_BAD_PARAMS_COUNT = @"Bad parameters number";
static NSString *S_API_IN_PROGRESS = @"Request already is in progress";
static NSString *S_API_BAD_PATH = @"Invalid API path";
static NSString *S_API_CANT_GET_NEXT_QUESTION = @"Can't get next question: %@";
static NSString *S_NOTHING_TO_BE_CHANGED = @"Nothing to be changed";

static NSString *S_PASSWORD_RESET_QUESTION = @"Do you really want to reset your password?";
static NSString *S_CHECK_YOUR_MAILBOX = @"Check your mailbox please";
static NSString *S_ENTER_CONFIRM_CODE = @"Enter confirmation code from SMS:";
static NSString *S_SMS_CONFIRM_PLACEHOLDER = @"Please type confirmation code from SMS";
static NSString *S_UPDATED_BUT_SYNC_ERROR = @"Operation successful, but synchronization error happened";
static NSString *S_OBJECTIVE_ADDED = @"Objective for the student added successfully";

static NSString *S_CONFIRM_EMAIL_SENT = @"We have sent a confirmation email to your email. Please follow instructions in this email.";

static NSString *S_CHOOSE_COUNTRY = @"Choose your country";
static NSString *S_CHOOSE_STUDENT = @"Choose student";
static NSString *S_CHOOSE_GRADE = @"Choose grade";
static NSString *S_CHOOSE_SUBJECT = @"Choose subject";
static NSString *S_CHOOSE_SKILL = @"Choose skill";
static NSString *S_CHOOSE_CATEGORY = @"Choose category";
static NSString *S_CHOOSE_SUBCATEGORY = @"Choose subcategory";

static NSString *S_NO_SKILLS_SELECTED = @"At least one skill should be selected!";

static NSString *S_RIGHT_ANSWER = @"Right!";
static NSString *S_WRONG_ANSWER = @"Wrong";
static NSString *S_NO_MORE_QUESTIONS = @"We don't have unanswered questions for the objective anymore at the time. Please return later to complete this objective.";

static NSString *S_ALL_GRADES = @"All grades";
static NSString *S_ALL_SUBJECTS = @"All subjects";

static NSString *S_STORE_IS_EMPTY = @"No rewards found. Please ask parents to add rewards for you.";

static NSString *S_MAKE_REWARD_UNAVAILABLE = @"Make unavailable to student";
static NSString *S_MAKE_REWARD_AVAILABLE = @"Make available to student";

static NSString *S_ADD_TO_WISHLIST = @"Add to wish list";
static NSString *S_REMOVE_FROM_WISHLIST = @"Remove from wish list";

static NSString *S_SET_AS_NEXT = @"Set as my next reward!";
static NSString *S_NO_SELECTED_REWARDS = @"At least one reward must be selected!"; // when parent deselects all rewards
static NSString *S_UNSET_AS_NEXT = @"I don't want it anymore";
static NSString *S_NEXT_REWARD_NOT_SELECTED = @"Please select your next reward from the list.";
static NSString *S_SELECT_NEXT_REWARD_FIRST = @"Please go to rewards screen and select your next reward first!";

static NSString *S_RETURN_BONUS = @"Return bonus!";
static NSString *S_BONUS = @"Bonus!";
static NSString *S_BONUS_ROUND = @"Bonus round!";
static NSString *S_SECRET = @"Secret!";
static NSString *S_FINAL_BONUS = @"Final bonus!";
static NSString *S_OBJECTIVE_IS_OVER_CONGRATS = @"Congratulations! You have completed the objective!";
static NSString *S_CANCEL_OBJECTIVE_CONFIRM = @"Do you really want to cancel this objective?\nNote: student current $$ balance will be preserved if any.";
static NSString *S_LESSON_IS_OVER_CONGRATS = @"Congratulations! You have completed today's practice!";
static NSString *S_LESSON_IS_ALREADY_COMPLETED = @"You have already completed today's practice for this subject!";
static NSString *S_ASK_FOR_BONUS_ROUND = @"Do you wish to play a bonus round and grab more coins?";
static NSString *S_BONUS_ROUND_IS_OVER_CONGRATS = @"Congratulations! You have completed the bonus round!";
static NSString *S_NOTHING_TO_DO_FOR_TODAY = @"Today you don't have any pending tasks for this objective. Please return tomorrow or choose another objective.";

// notification names
static NSString *S_NTF_STUDENT_SWITCHED = @"S_NTF_STUDENT_SWITCHED";
static NSString *S_NTF_OBJECTIVE_ADDED = @"S_NTF_OBJECTIVE_ADDED";

static NSString *S_NTF_STUDENT_PROFILE_SYNCED = @"S_NTF_STUDENT_PROFILE_SYNCED";
static NSString *S_NTF_PARENT_PROFILE_SYNCED = @"S_NTF_PARENT_PROFILE_SYNCED";

// sent by API class, when the app was inactive for a long time
static NSString *S_NTF_INACTIVITY_TIMOUT = @"S_NTF_INACTIVITY_TIMOUT";

// if app inactivity time >= [session timeout * INACTIVITY_TIMEOUT_MULTIPLIER],
// S_NTF_INACTIVITY_TIMOUT notification will be sent to subscribers.
static const NSUInteger INACTIVITY_TIMEOUT_MULTIPLIER = 3;


#endif
