# FlipBIP - BIP32/39/44 Secure Enclave edition

[![Build](https://github.com/astrrra/FlipBIP/actions/workflows/build.yml/badge.svg?branch=main)](https://github.com/astrrra/FlipBIP/actions/workflows/build.yml)

## Crypto toolkit for Flipper Zero
- Using Trezor crypto libs from `core/v2.5.3` release

## Background

This is a fork of the FlipBIP application with support for the integrated secure enclave of the Flipper Zero. This functionality was rolled back into the original app as of v2.1.

## How to install on Flipper Zero
- Install `ufbt` if you haven't already. Usually you do it with `python3 -m pip install ufbt`
- Plug your Flipper Zero in via USB
- Clone this github repository and navigate into it in your terminal
- Run `ufbt launch` to compile, upload, and run the app.

## Status

### Complete

- Trezor crypto C code ported into `crypto` subfolder
  - Adapted to use Flipper hardware RNG (see `crypto/rand.c`)
  - Imports and some C library functions modified for compatibility with FBT
- Navigation and UI adapted from FAP Boilerplate app
- BIP39 mnemonic generation
  - 24, 18, or 12 words configured in settings
- BIP39 mnemonic to BIP39 seed generation
- Hierarchical Deterministic (HD) wallet generation from seed
  - Generation of offline `m/44'/0'/0'/0` BTC wallet
  - Generation of offline `m/44'/60'/0'/0` ETH wallet (coded from the $SPORK Castle of ETHDenver 2023!)
  - Generation of offline `m/44'/3'/0'/0` DOGE wallet
  - Similar features to: https://iancoleman.io/bip39/
- Saving wallets to SD card
  - Wallets are saved to SD card upon creation in `apps_data/flipbip`
      - NOTE: `apps_data` folder must already exist on SD card!
  - Saved wallets can be viewed between app runs
  - Wallets are encrypted with a randomly generated key, and that key is stored in the secure enclave of the STM32WB55 MCU (slot 11). The same key is also used for encrypting the U2F files in the official U2F app. Slots 0-10 contain pre-shared factory keys that are the same for all devices, other slots are empty by default and are filled with randomly generated keys when used. The keys are non-extractable (if you manage to extract them from the secure enclave - please email astra@flipperzero.one with the key from slot 8 as a sample), therefore they can't be backed up (which is the whole point of the secure enclave).
      - `.flipbip.dat` file is specific to your Flipper Zero, it can't be opened on any other Flipper Zero or any other device in general.
      - `.flipbip.dat.bak` is created as a backup and never accessed, you can store it somewhere safe in case your SD card fails.
      - If you want to externally back up your wallet, it is recommended to store them separately from your Flipper Zero, as it has the encryption key to the files.
      - If you lose your Flipper Zero, you lose the encryption key. Make sure to back up your seed phrase somewhere safe. You find it by opening any wallet (BTC/ETH/DOGE) on your device.
      - Moving the SD card or wallet files from one Flipper Zero to the other will result in them not functioning due to the keys being different.
  - NOTE: The wallets should be close to impossible to crack off of a Flipper, however anyone with access to your Flipper with the app installed can load a wallet in the `apps_data/flipbip` directory. Therefore, it is HIGHLY RECOMMENDED to use the BIP39 passphrase functionality and store the passphrase in your brain or on paper separately from the Flipper!
- BIP39 passphrase support
  - Configured in settings, not persisted between runs for security
- Import your own mnemonic
  - Lots of typing required but you can now use the wallet with an existing mnemonic you have saved
  - Useful to convert paper backup to keys and receive addresses without relying on a laptop or phone
- Improved receive address generation features
  - Addresses are now generated at the same time as other pieces of wallet info
    - This slows down initial wallet load, but makes UI much more responsive
  - QR code files are now generated for each address and stored in the `apps_data/flipbip` directory
    - This app is required to view the QR code files: https://github.com/bmatcuk/flipperzero-qrcode (included in RM firmware)
    - NOTE: This happens during the `View Wallet` step; you must view a wallet after generating/importing a wallet in order to ensure the address QR files are correct
- Broke out crypto functionality into its own library using `fap_private_libs` feature

### Work in Progress

- More coin types
  - Support for more custom BIP32 wallet paths

### (FAR) Future

- Custom wallet security
  - User specified password
- USB/Bluetooth wallet functionality

## Donate to the original author:
- ETH (or ERC-20): `xtruan.eth` or `0xa9Ad79502cdaf4F6881f3C2ef260713e5B771CE2`
- BTC: `16RP5Ui5QrWrVh2rR7NKAPwE5A4uFjCfbs`
