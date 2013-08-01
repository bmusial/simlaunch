/*
 * Author: Landon Fuller <landonf@plausiblelabs.com>
 *
 * Copyright (c) 2010 Plausible Labs Cooperative, Inc.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#import <Cocoa/Cocoa.h>

#import "BundlerConfigWindowController.h"
#import "BundlerTool.h"

typedef enum {
    SBADefaultSimulatorUndefined    = -9999,
    SBADefaultSimulatorUserSelect   = 0,
    SBADefaultSimulatoriPhone       = 1,
    SBADefaultSimulatoriPad         = 2
} SBADefaultSimulator;

@interface BundlerAppDelegate : NSObject <BundlerConfigWindowControllerDelegate> {
@private
    SBADefaultSimulator _defaultSimulator;
    BOOL _hasCommandLineArguments;
    
    /** If NO, no files were opened by the app. Used to determine if the app should
     * immediately exit. */
    BOOL _receivedDroppedFiles;

    /** Active task count. When it hits 0, the app exits. */
    NSUInteger _activeTasks;

    /** Bundler tool manager */
    BundlerTool *_tool;

    /** Active BundlerConfigWindowController instances. */
    NSMutableSet *_appConfigControllers;

    /** If YES, the open panel is being displayed */
    BOOL _openPanelActive;
}

- (IBAction) openFile: (id) sender;

@end
