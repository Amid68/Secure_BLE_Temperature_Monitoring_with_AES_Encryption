/**
 * @file common.h
 * @brief Common definitions and functions
 *
 * This file contains global includes, macros, constants,
 * typedefs, and function prototypes shared across the
 * firmware project. 
 * 
 * @author Ameed Othman
 * @date 05.12.2024
 */

#ifndef __COMMON_H__
#define __COMMON_H__

/* Standard Libraries */
#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/sensor.h>
#include <sys/printk.h>
#include <logging/log.h>
#include <string.h>
#include <stdio.h>

/* Zephyr Logging Module Configuration */
LOG_MODULE_REGISTER(app_logger, LOG_LEVEL_DBG);

/* Application Information */
#define APP_NAME "Secure BLE Temperature Monitor"
#define APP_VERSION "1.0.0"

/* Common Macros */
#define SUCCESS 0
#define FAILURE -1

/* Time Constants */
#define SENSOR_READ_INTERVAL_MS 1000

/* AES Encryption Constants */
#define AES_KEY_SIZE 16
#define AES_IV_SIZE 16
#define AES_BLOCK_SIZE 16

/* BLE Transmission Constants */
#define BLE_MAX_DATA_LEN 20 // Maximum data length for BLE transmission

/* Error Codes Enumeration */
typedef enum {
    ERR_NONE = 0,
    ERR_SENSOR_INIT = -1,
    ERR_SENSOR_READ = -2,
    ERR_ENCRYPTION_INIT = -3,
    ERR_ENCRYPTION_PROCESS = -4,
    ERR_BLE_INIT = -5,
    ERR_BLE_ADV_START = -6,
    ERR_BLE_SEND = -7,
} error_code_t;

/* Sensor Data Structure */
typedef struct {
    double temperature_celsius;
    int64_t timestamp_ms;
} sensor_data_t;

/* Function Prototypes */

/**
 * @brief Application-wide error handler.
 * 
 * @param err_code Error code indicating the type of error.
 */
void app_error_handler(error_code_t err_code);

/**
 * @brief Initialize all application modules.
 * 
 * Calls initialization functions for the sensor, encryption, and BLE modules.
 * 
 * @return 0 if successful, -1 otherwise.
 */
int app_modules_init(void);

#endif