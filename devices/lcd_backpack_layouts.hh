#ifdef __INTERNAL_INCLUDE_STRUCTS__

template<>
struct LcdBackPack<0, 1, 2, 3, 4, 5, 6, 7> {
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<0, 1, 2, 4, 5, 6, 7, 3> {
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<0, 1, 6, 2, 3, 4, 5, 7> {
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<0, 1, 7, 2, 3, 4, 5, 6> {
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<0, 1, 3, 4, 5, 6, 7, 2> {
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<0, 1, 7, 3, 4, 5, 6, 2> {
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<0, 2, 1, 3, 4, 5, 6, 7> {
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<0, 2, 1, 4, 5, 6, 7, 3> {
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<0, 6, 1, 2, 3, 4, 5, 7> {
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<0, 7, 1, 2, 3, 4, 5, 6> {
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<0, 3, 1, 4, 5, 6, 7, 2> {
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<0, 7, 1, 3, 4, 5, 6, 2> {
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<0, 5, 6, 1, 2, 3, 4, 7> {
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<0, 5, 7, 1, 2, 3, 4, 6> {
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<0, 6, 5, 1, 2, 3, 4, 7> {
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<0, 7, 5, 1, 2, 3, 4, 6> {
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<0, 6, 7, 1, 2, 3, 4, 5> {
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<0, 7, 6, 1, 2, 3, 4, 5> {
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<0, 2, 3, 4, 5, 6, 7, 1> {
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<0, 2, 7, 3, 4, 5, 6, 1> {
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<0, 3, 2, 4, 5, 6, 7, 1> {
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<0, 7, 2, 3, 4, 5, 6, 1> {
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<0, 6, 7, 2, 3, 4, 5, 1> {
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<0, 7, 6, 2, 3, 4, 5, 1> {
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<1, 0, 2, 3, 4, 5, 6, 7> {
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<1, 0, 2, 4, 5, 6, 7, 3> {
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<1, 0, 6, 2, 3, 4, 5, 7> {
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<1, 0, 7, 2, 3, 4, 5, 6> {
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<1, 0, 3, 4, 5, 6, 7, 2> {
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<1, 0, 7, 3, 4, 5, 6, 2> {
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<2, 0, 1, 3, 4, 5, 6, 7> {
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<2, 0, 1, 4, 5, 6, 7, 3> {
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<6, 0, 1, 2, 3, 4, 5, 7> {
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<7, 0, 1, 2, 3, 4, 5, 6> {
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<3, 0, 1, 4, 5, 6, 7, 2> {
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<7, 0, 1, 3, 4, 5, 6, 2> {
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<5, 0, 6, 1, 2, 3, 4, 7> {
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<5, 0, 7, 1, 2, 3, 4, 6> {
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<6, 0, 5, 1, 2, 3, 4, 7> {
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<7, 0, 5, 1, 2, 3, 4, 6> {
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<6, 0, 7, 1, 2, 3, 4, 5> {
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<7, 0, 6, 1, 2, 3, 4, 5> {
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<2, 0, 3, 4, 5, 6, 7, 1> {
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<2, 0, 7, 3, 4, 5, 6, 1> {
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<3, 0, 2, 4, 5, 6, 7, 1> {
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<7, 0, 2, 3, 4, 5, 6, 1> {
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<6, 0, 7, 2, 3, 4, 5, 1> {
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<7, 0, 6, 2, 3, 4, 5, 1> {
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<1, 2, 0, 3, 4, 5, 6, 7> {
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<1, 2, 0, 4, 5, 6, 7, 3> {
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<1, 6, 0, 2, 3, 4, 5, 7> {
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<1, 7, 0, 2, 3, 4, 5, 6> {
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<1, 3, 0, 4, 5, 6, 7, 2> {
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<1, 7, 0, 3, 4, 5, 6, 2> {
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<2, 1, 0, 3, 4, 5, 6, 7> {
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<2, 1, 0, 4, 5, 6, 7, 3> {
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<6, 1, 0, 2, 3, 4, 5, 7> {
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<7, 1, 0, 2, 3, 4, 5, 6> {
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<3, 1, 0, 4, 5, 6, 7, 2> {
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<7, 1, 0, 3, 4, 5, 6, 2> {
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<5, 6, 0, 1, 2, 3, 4, 7> {
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<5, 7, 0, 1, 2, 3, 4, 6> {
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<6, 5, 0, 1, 2, 3, 4, 7> {
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<7, 5, 0, 1, 2, 3, 4, 6> {
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<6, 7, 0, 1, 2, 3, 4, 5> {
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<7, 6, 0, 1, 2, 3, 4, 5> {
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<2, 3, 0, 4, 5, 6, 7, 1> {
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<2, 7, 0, 3, 4, 5, 6, 1> {
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<3, 2, 0, 4, 5, 6, 7, 1> {
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<7, 2, 0, 3, 4, 5, 6, 1> {
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<6, 7, 0, 2, 3, 4, 5, 1> {
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<7, 6, 0, 2, 3, 4, 5, 1> {
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<4, 5, 6, 0, 1, 2, 3, 7> {
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<4, 5, 7, 0, 1, 2, 3, 6> {
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<4, 6, 5, 0, 1, 2, 3, 7> {
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<4, 7, 5, 0, 1, 2, 3, 6> {
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<4, 6, 7, 0, 1, 2, 3, 5> {
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<4, 7, 6, 0, 1, 2, 3, 5> {
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<5, 4, 6, 0, 1, 2, 3, 7> {
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<5, 4, 7, 0, 1, 2, 3, 6> {
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<6, 4, 5, 0, 1, 2, 3, 7> {
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<7, 4, 5, 0, 1, 2, 3, 6> {
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<6, 4, 7, 0, 1, 2, 3, 5> {
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<7, 4, 6, 0, 1, 2, 3, 5> {
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<5, 6, 4, 0, 1, 2, 3, 7> {
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<5, 7, 4, 0, 1, 2, 3, 6> {
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t backlight : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<6, 5, 4, 0, 1, 2, 3, 7> {
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t backlight : 1;

};
template<>
struct LcdBackPack<7, 5, 4, 0, 1, 2, 3, 6> {
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t backlight : 1;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<6, 7, 4, 0, 1, 2, 3, 5> {
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<7, 6, 4, 0, 1, 2, 3, 5> {
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<5, 6, 7, 0, 1, 2, 3, 4> {
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<5, 7, 6, 0, 1, 2, 3, 4> {
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<6, 5, 7, 0, 1, 2, 3, 4> {
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<7, 5, 6, 0, 1, 2, 3, 4> {
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<6, 7, 5, 0, 1, 2, 3, 4> {
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<7, 6, 5, 0, 1, 2, 3, 4> {
    uint8_t data : 4;
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<1, 2, 3, 4, 5, 6, 7, 0> {
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<1, 2, 7, 3, 4, 5, 6, 0> {
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<1, 3, 2, 4, 5, 6, 7, 0> {
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<1, 7, 2, 3, 4, 5, 6, 0> {
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<1, 6, 7, 2, 3, 4, 5, 0> {
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<1, 7, 6, 2, 3, 4, 5, 0> {
    uint8_t backlight : 1;
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<2, 1, 3, 4, 5, 6, 7, 0> {
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<2, 1, 7, 3, 4, 5, 6, 0> {
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<3, 1, 2, 4, 5, 6, 7, 0> {
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<7, 1, 2, 3, 4, 5, 6, 0> {
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<6, 1, 7, 2, 3, 4, 5, 0> {
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<7, 1, 6, 2, 3, 4, 5, 0> {
    uint8_t backlight : 1;
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<2, 3, 1, 4, 5, 6, 7, 0> {
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<2, 7, 1, 3, 4, 5, 6, 0> {
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t data : 4;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<3, 2, 1, 4, 5, 6, 7, 0> {
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t data : 4;

};
template<>
struct LcdBackPack<7, 2, 1, 3, 4, 5, 6, 0> {
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t data : 4;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<6, 7, 1, 2, 3, 4, 5, 0> {
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<7, 6, 1, 2, 3, 4, 5, 0> {
    uint8_t backlight : 1;
    uint8_t enable : 1;
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<5, 6, 7, 1, 2, 3, 4, 0> {
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t rw : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<5, 7, 6, 1, 2, 3, 4, 0> {
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t rs : 1;
    uint8_t enable : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<6, 5, 7, 1, 2, 3, 4, 0> {
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t rs : 1;
    uint8_t enable : 1;

};
template<>
struct LcdBackPack<7, 5, 6, 1, 2, 3, 4, 0> {
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t rw : 1;
    uint8_t enable : 1;
    uint8_t rs : 1;

};
template<>
struct LcdBackPack<6, 7, 5, 1, 2, 3, 4, 0> {
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t rs : 1;
    uint8_t rw : 1;

};
template<>
struct LcdBackPack<7, 6, 5, 1, 2, 3, 4, 0> {
    uint8_t backlight : 1;
    uint8_t data : 4;
    uint8_t enable : 1;
    uint8_t rw : 1;
    uint8_t rs : 1;

};

#endif
