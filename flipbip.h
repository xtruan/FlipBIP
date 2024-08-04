#pragma once

#include <furi.h>
#include <furi_hal.h>
#include <gui/gui.h>
#include <input/input.h>
#include <stdlib.h>
//#include <notification/notification_messages.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/submenu.h>
#include <gui/scene_manager.h>
#include <gui/modules/dialog_ex.h>
#include <gui/modules/variable_item_list.h>
#include <gui/modules/text_input.h>
#include "scenes/flipbip_scene.h"
#include "views/flipbip_scene_1.h"

#define FLIPBIP_VERSION "v1.16"

#define COIN_BTC 0
#define COIN_DOGE 3
#define COIN_DASH 5
#define COIN_ETH 60
#define COIN_ZEC 133
#define COIN_PIRATE 660
#define COIN_COSA 770

#define TEXT_BUFFER_SIZE 256

typedef struct {
    Gui* gui;
    // NotificationApp* notification;
    ViewDispatcher* view_dispatcher;
    Submenu* submenu;
    SceneManager* scene_manager;
    VariableItemList* variable_item_list;
    TextInput* text_input;
    DialogEx* renew_dialog;
    FlipBipScene1* flipbip_scene_1;
    char* mnemonic_menu_text;
    // Settings options
    int bip39_strength;
    int passphrase;
    // Main menu options
    int bip44_coin;
    int overwrite_saved_seed;
    int import_from_mnemonic;
    // Text input
    int input_state;
    char passphrase_text[TEXT_BUFFER_SIZE];
    char import_mnemonic_text[TEXT_BUFFER_SIZE];
    char input_text[TEXT_BUFFER_SIZE];

    void (*wallet_create)(void* context);
} FlipBip;

typedef enum {
    FlipBipViewIdStartscreen,
    FlipBipViewIdMenu,
    FlipBipViewIdScene1,
    FlipBipViewIdSettings,
    FlipBipViewIdTextInput,
    FlipBipViewRenewConfirm,
} FlipBipViewId;

typedef enum {
    FlipBipStrength128,
    FlipBipStrength192,
    FlipBipStrength256,
} FlipBipStrengthState;

typedef enum {
    FlipBipPassphraseOff,
    FlipBipPassphraseOn,
} FlipBipPassphraseState;

typedef enum {
    FlipBipCoinBTC0,
    FlipBipCoinCOSA3,
    FlipBipCoinETH60,
    FlipBipCoinDASH3,
    FlipBipCoinDOGE3,
    FlipBipCoinPIRATE3,
    FlipBipCoinZEC133,
} FlipBipCoin;

typedef enum {
    FlipBipTextInputDefault,
    FlipBipTextInputPassphrase,
    FlipBipTextInputMnemonic
} FlipBipTextInputState;

typedef enum {
    FlipBipStatusSuccess = 0,
    FlipBipStatusReturn = 10,
    FlipBipStatusLoadError = 11,
    FlipBipStatusSaveError = 12,
    FlipBipStatusMnemonicCheckError = 13,
} FlipBipStatus;

typedef enum {
    SubmenuIndexScene1BTC = 10,
    SubmenuIndexScene1COSA,
    SubmenuIndexScene1ETH,
    SubmenuIndexScene1DASH,
    SubmenuIndexScene1DOGE,
    SubmenuIndexScene1PIRATE,
    SubmenuIndexScene1ZEC,
    SubmenuIndexScene1New,
    SubmenuIndexScene1Renew,
    SubmenuIndexScene1Import,
    SubmenuIndexSettings,
    SubmenuIndexNOP,
} SubmenuIndex;
