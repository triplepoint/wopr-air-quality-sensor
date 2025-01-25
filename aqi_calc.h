#include <math.h>
// See: https://document.airnow.gov/technical-assistance-document-for-the-reporting-of-daily-air-quailty.pdf
// See: https://en.wikipedia.org/wiki/Air_quality_index#Computing_the_AQI

float _aqi_piece(float val, float val_l, float val_h, float aqi_l, float aqi_h) {
    return round(((aqi_h - aqi_l) / (val_h - val_l) * (val - val_l)) + aqi_l);
}

float aqi_pm2_5(float pm_val) {
    if (pm_val == NAN) {
        return NAN;
    }
    else if (pm_val <= 9.0) {
        return _aqi_piece(pm_val, 0.0, 9.0, 0.0, 50.0);
    }
    else if (pm_val <= 35.4) {
        return _aqi_piece(pm_val, 9.1, 35.4, 51.0, 100.0);
    }
    else if (pm_val <= 55.4) {
        return _aqi_piece(pm_val, 35.5, 55.4, 101.0, 150.0);
    }
    else if (pm_val <= 125.4) {
        return _aqi_piece(pm_val, 55.5, 125.4, 151.0, 200.0);
    }
    else if (pm_val <= 225.4) {
        return _aqi_piece(pm_val, 125.5, 225.4, 201.0, 300.0);
    }
    else if (pm_val <= 325.4) {
        return _aqi_piece(pm_val, 225.5, 325.4, 301.0, 500.0);
    }
    else {
        return 500.0;
    }
}

float aqi_pm_10_0(float pm_val) {
    if (pm_val == NAN) {
        return NAN;
    }
    else if (pm_val <= 54.0) {
        return _aqi_piece(pm_val, 0.0, 54.0, 0.0, 50.0);
    }
    else if (pm_val <= 154.0) {
        return _aqi_piece(pm_val, 55.0, 154.0, 51.0, 100.0);
    }
    else if (pm_val <= 254.0) {
        return _aqi_piece(pm_val, 155.0, 254.0, 101.0, 150.0);
    }
    else if (pm_val <= 354.0) {
        return _aqi_piece(pm_val, 255.0, 354.0, 151.0, 200.0);
    }
    else if (pm_val <= 424.0) {
        return _aqi_piece(pm_val, 355.0, 424.0, 201.0, 300.0);
    }
    else if (pm_val <= 604.0) {
        return _aqi_piece(pm_val, 425.0, 604.0, 301.0, 500.0);
    }
    else {
        return 500.0;
    }
}
