#ifndef FIRE_MODE_H
#define FIRE_MODE_H

#define FIRE_DEFAULT_COOLING 8-0
#define FIRE_DEFAULT_SPARKING 120

#include <Arduino.h>
#include <FastLed.h>

#include <audiolight/AudioLightMode.h>
#include <audiolight/JsonUtil.h>

class FireMode : public AudioLightMode {

private:
    bool _refresh = true;
    bool _reverse = false;

    CRGBPalette16 _heat = CRGBPalette16(HeatColors_p);
    CRGBPalette16 *_firePalette = &_heat;

    uint8_t _cooling =  FIRE_DEFAULT_COOLING;
    uint8_t _sparking =  FIRE_DEFAULT_SPARKING;

    uint8_t *_heatMap;

public:
  FireMode(CLEDController *ledController, CRGB *leds, uint16_t numLeds, uint16_t *bands,  uint16_t numBands)
      : AudioLightMode(ledController, leds, numLeds, bands, numBands) {
    _heatMap = (uint8_t *) malloc(sizeof(uint8_t) * numLeds);
    memset(_heatMap, 0, sizeof(uint8_t) * numLeds);
  };
  String getId();
  void tick();
  void sampleComplete();
  void enable();
  void updateConfig(JsonObject &root);
  void writeConfig(JsonObject &root);
};

#endif