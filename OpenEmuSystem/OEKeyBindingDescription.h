/*
 Copyright (c) 2012, OpenEmu Team
 
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of the OpenEmu Team nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY OpenEmu Team ''AS IS'' AND ANY
 EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL OpenEmu Team BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>

#import <OpenEmuSystem/OEBindingDescription.h>

NS_ASSUME_NONNULL_BEGIN

@class OEKeyBindingGroupDescription;

typedef NS_ENUM(NSUInteger, OEGlobalButtonIdentifier) {
    OEGlobalButtonIdentifierUnknown,

    OEGlobalButtonIdentifierSaveState,
    OEGlobalButtonIdentifierLoadState,
    OEGlobalButtonIdentifierQuickSave,
    OEGlobalButtonIdentifierQuickLoad,
    OEGlobalButtonIdentifierFullScreen,
    OEGlobalButtonIdentifierMute,
    OEGlobalButtonIdentifierVolumeDown,
    OEGlobalButtonIdentifierVolumeUp,

    OEGlobalButtonIdentifierStop,
    OEGlobalButtonIdentifierReset,
    OEGlobalButtonIdentifierPause,
    OEGlobalButtonIdentifierRewind,
    OEGlobalButtonIdentifierFastForward,
    OEGlobalButtonIdentifierSlowMotion,
    OEGlobalButtonIdentifierStepFrameBackward,
    OEGlobalButtonIdentifierStepFrameForward,
    OEGlobalButtonIdentifierDisplayMode,
    OEGlobalButtonIdentifierScreenshot,

    OEGlobalButtonIdentifierCount,

    OEGlobalButtonIdentifierFlag = 1 << 24,
};

NSString *NSStringFromOEGlobalButtonIdentifier(OEGlobalButtonIdentifier identifier);

@interface OEKeyBindingDescription : OEBindingDescription

@property(readonly, copy) NSString *name;
@property(readonly) NSUInteger index;
@property(readonly, getter=isAnalogic) BOOL analogic;
@property(weak, nullable, nonatomic, readonly) OEKeyBindingGroupDescription *hatSwitchGroup;
@property(weak, nullable, nonatomic, readonly) OEKeyBindingGroupDescription *axisGroup;

// Returns YES if the key does not depend on the player number
@property(readonly, getter=isSystemWide) BOOL systemWide;

// Returns nil if the key does not have an opposite key
@property(readonly, nullable, weak) OEKeyBindingDescription *oppositeKey;
// Returns nil if the key is not part of a hat switch
@property(readonly, nullable, copy) NSArray<OEKeyBindingDescription *> *hatSwitchKeys;

- (void)enumerateHatSwitchKeysUsingBlock:(void(^)(OEKeyBindingDescription *key, BOOL *stop))block;

@end

@interface OEGlobalKeyBindingDescription : OEKeyBindingDescription
@property (readonly) OEGlobalButtonIdentifier buttonIdentifier;
@end

NS_ASSUME_NONNULL_END
