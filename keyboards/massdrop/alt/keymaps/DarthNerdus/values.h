// Layers
#define _BASE 0
#define _MAC 1
#define _WOW 2
#define _WOWMB 3
#define _WOWTYPE 4
#define _FUNCTIONS 5

// Personal Colors
#define RED {0, 255, 150}
#define JR_WHIT {0, 0, 125}
#define JR_AZUR {132, 102, 175}
#define JR_AZUN {132, 102, 100}
#define CYANUND {128, 255, 100}

// RGB Stuff
extern rgb_config_t rgb_matrix_config;
#define BRED {HSV_RED}
#define CORAL {HSV_CORAL}
#define ORANGE {HSV_ORANGE}
#define GOLDEN {HSV_GOLDENROD}
#define GOLD {HSV_GOLD}
#define YELLOW {HSV_YELLOW}
#define CHART {HSV_CHARTREUSE}
#define GREEN {HSV_GREEN}
#define SPRING {HSV_SPRINGGREEN}
#define TURQ {HSV_TURQUOISE}
#define TEAL {HSV_TEAL}
#define CYAN {HSV_CYAN}
#define AZURE {HSV_AZURE}
#define BLUE {HSV_BLUE}
#define PURPLE {HSV_PURPLE}
#define MAGENTA {HSV_MAGENTA}
#define PINK {HSV_PINK}

// Shortcuts to check if CTRL/SHIFT/ALT are held.
#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))