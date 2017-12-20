#ifndef COLORMODEL_H
#define COLORMODEL_H


class ColorModel
{
    int hue;
    int saturation;
    int value;
public:
    ColorModel();
    ColorModel(int h, int s, int v);
    int GetHue();
    void SetHue(int h);
    int GetSaturation();
    void SetSaturation(int s);
    int GetValue();
    void SetValue(int v);
};

#endif // COLORMODEL_H
