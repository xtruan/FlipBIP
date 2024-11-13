#include <flipbip_coins.h>

// bip44_coin, xprv_version, xpub_version, addr_version, wif_version, addr_format
const uint32_t COIN_INFO_ARRAY[NUM_COINS][COIN_INFO_SIZE] = {
    {0, 0x0488ade4, 0x0488b21e, 0x00, 0x80, FlipBipCoinBTC0},
    {60, 0x0488ade4, 0x0488b21e, 0x00, 0x80, FlipBipCoinETH60},
    {3, 0x02fac398, 0x02facafd, 0x1e, 0x9e, FlipBipCoinBTC0},
    {133, 0x0488ade4, 0x0488b21e, 0x1cb8, 0x80, FlipBipCoinZEC133},
};

// coin_name, derivation_path, coin name
const char* COIN_TEXT_ARRAY[NUM_COINS][COIN_TEXT_SIZE] = {
    {"BTC", "m/44'/0'/0'/0", "bitcoin:"},
    {"ETH", "m/44'/60'/0'/0", "ethereum:"},
    {"DOGE", "m/44'/3'/0'/0", "dogecoin:"},
    {"ZEC", "m/44'/133'/0'/0", "zcash:"}};