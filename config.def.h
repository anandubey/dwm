/*=============================================================================
 *                                                                             
 *                            DWM Config                                       
 *                       @author:- anandubey                                   
 *                                                                             
 *===========================================================================*/


/* ******************** Configurations ******************** */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 8;       	/* horiz inner gap between windows */
static const unsigned int gappiv    = 8;       	/* vert inner gap between windows */
static const unsigned int gappoh    = 8;       	/* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 8;       	/* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 4;        /* horizontal padding for statusbar */
static const int vertpadbar         = 4;        /* vertical padding for statusbar */


/* ******************** Fonts ******************** */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:style:medium:size=9",
                                        "Material Design Icons:size=9" }; //"Font Awesome 6 Free Solid:style=Solid:size=9"
static const char dmenufont[]       = "JetBrainsMono Nerd Font:style:medium:size=9";


/* ******************** Colors ******************** */
static const char black[]       = "#1e2122";
static const char gray2[]       = "#282b2c"; // unfocused window border
static const char gray3[]       = "#5d6061";
static const char gray4[]       = "#282b2c";
static const char blue[]        = "#6f8faf";  // focused window border
static const char green[]       = "#89b482";
static const char red[]         = "#ec6b64";
static const char orange[]      = "#d6b676";
static const char yellow[]      = "#d1b171";
static const char pink[]        = "#cc7f94";
static const char col_borderbar[]  = "#1e2122"; // inner border


static const char col_gray1[]       = "#232627";
static const char col_gray2[]       = "#484b4c";
static const char col_gray3[]       = "#9f937d";
static const char col_gray4[]       = "#ddd4c4";
static const char col_cyan[]        = "#484b4c";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};


/* ******************** Tags/Workspaces ******************** */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };


/* ******************** Window Rules ******************** */
static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      						instance    title       tags mask     iscentered   isfloating   monitor */
	{ "Gimp",     						NULL,       NULL,       0,            0,           1,           -1 },
	{ "Inkscape",     					NULL,       NULL,       0,            0,           1,           -1 },
	{ "Firefox",  						NULL,       NULL,       1 << 8,       0,           0,           -1 },
	{ "Viewnior",  						NULL,       NULL,       0,       	  1,           1,           -1 },
	{ "MPlayer",  						NULL,       NULL,       0,       	  1,           1,           -1 },
	{ "Pcmanfm",  						NULL,       NULL,       0,       	  1,           1,           -1 },
	{ "Music",  						NULL,       NULL,       0,       	  1,           1,           -1 },
	{ "Yad",  							NULL,       NULL,       0,       	  1,           1,           -1 },
	{ "feh",  							NULL,       NULL,       0,       	  1,           1,           -1 },
	{ "Pavucontrol",  					NULL,       NULL,       0,       	  1,           1,           -1 },
	{ "Lxappearance",  					NULL,       NULL,       0,       	  1,           1,           -1 },
	{ "alacritty-float",  				NULL,       NULL,       0,       	  1,           1,           -1 },
	{ "VirtualBox Manager",  			NULL,       NULL,       0,       	  1,           1,           -1 },
	{ "Nm-connection-editor",  			NULL,       NULL,       0,       	  1,           1,           -1 },
	{ "Xfce4-power-manager-settings",  	NULL,       NULL,       0,       	  1,           1,           -1 },
};


/* ******************** Layout(s) ******************** */
static const float mfact     = 0.55; 		/* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    		/* number of clients in master area */
static const int resizehints = 0;    		/* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; 		/* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  					/* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
};


/* ******************** Key definitions ******************** */
/* key definitions */
#define MOD Mod1Mask
#define ALT Mod4Mask
#define SHIFT ShiftMask
#define CTRL ControlMask

#define TAGKEYS(KEY,TAG) \
	{ MOD,					KEY,		view,			{.ui = 1 << TAG} }, \
	{ MOD|CTRL,				KEY,		toggleview,		{.ui = 1 << TAG} }, \
	{ MOD|SHIFT,			KEY,		tag,			{.ui = 1 << TAG} }, \
	{ MOD|ALT,				KEY,		tagview,		{.ui = 1 << TAG} }, \
	{ MOD|CTRL|SHIFT,		KEY,		toggletag,		{.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }


/* ******************** Commands ******************** */
static char dmenumon[2] 				= 	"0";
static const char *dmenucmd[]			= { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };

/* Launch Apps */
static const char *termcmd[]			= { "alacritty", 				NULL };
static const char *rofi[]				= { "rofi", "-show", "drun",	NULL };

/* Misc */
static const char *cpickcmd[]  			= { "color-gpick", 					NULL };
static const char *lockcmd[]  			= { "betterlockscreen", "--lock",	NULL };

/* Hardware keys for volume and brightness */
#include <X11/XF86keysym.h>
static const char *mutevol[]			= { "pamixer", "--toggle-mute",		NULL };
static const char *upvol[]				= { "pamixer", "-ui", "5",  		NULL };
static const char *downvol[]			= { "pamixer", "-ud", "5",    		NULL };
static const char *upbl[]				= { "brightnessctl", "set", "+5%",	NULL };
static const char *downbl[]				= { "brightnessctl", "set", "5-%",	NULL };

/* Screenshot */
static const char *shotnow[]			= { "takeshot", "--now",	NULL };
static const char *shotin5[]  			= { "takeshot", "--in5",	NULL };
static const char *shotin10[]  			= { "takeshot", "--in10",	NULL };
static const char *shotwin[]  			= { "takeshot", "--win",	NULL };
static const char *shotarea[]  			= { "takeshot", "--area",	NULL };


/* ******************** Keybindings ******************** */
static Key keys[] = {
	/* modifier						key						function        argument */

	// Hardware Keys ----------------------------------------------------------
	{ 0,					XF86XK_AudioMute,			spawn,		{.v = mutevol	} },
	{ 0,					XF86XK_AudioLowerVolume,	spawn,		{.v = downvol	} },
	{ 0,					XF86XK_AudioRaiseVolume,	spawn,		{.v = upvol		} },
	{ 0,					XF86XK_MonBrightnessUp,		spawn,		{.v = upbl		} },
	{ 0,					XF86XK_MonBrightnessDown,	spawn,		{.v = downbl	} },


	// Print Keys -------------------------------------------------------------
	{ 0,					XK_Print, 					spawn,		{.v = shotnow } },
	{ ALT,					XK_Print, 					spawn,		{.v = shotin5 } },
	{ SHIFT,				XK_Print, 					spawn,		{.v = shotin10 } },
	{ CTRL,					XK_Print, 					spawn,		{.v = shotwin } },
	{ ALT|CTRL,				XK_Print, 					spawn,		{.v = shotarea } },


	// Terminals --------------------------------------------------------------
	{ MOD,					XK_Return,					spawn,          {.v = termcmd } },
	// { MOD|SHIFT,			XK_Return, 					spawn, {.v = floatterm } },
	

	// Rofi Menus -------------------------------------------------------------
	{ MOD,					XK_p,						spawn,          {.v = rofi} },


	// Misc -----------
    { MOD|CTRL|SHIFT,		XK_p, 						spawn, {.v = cpickcmd } },
    { ALT|CTRL,				XK_l, 						spawn, {.v = lockcmd } },

	{ MOD|CTRL,				XK_b,						togglebar,      {0} },
	{ MOD,					XK_j,						focusstack,     {.i = +1 } },
	{ MOD,					XK_k,						focusstack,     {.i = -1 } },
	{ MOD|CTRL,				XK_i,						incnmaster,     {.i = +1 } },
	{ MOD|CTRL,				XK_d,						incnmaster,     {.i = -1 } },
	{ MOD,					XK_h,						setmfact,       {.f = -0.05} },
	{ MOD,					XK_l,						setmfact,       {.f = +0.05} },
	{ MOD|SHIFT,			XK_Return,					zoom,           {0} },

	{ MOD|ALT,				XK_u,      incrgaps,       {.i = +1 } },
	{ MOD|ALT|SHIFT,		XK_u,      incrgaps,       {.i = -1 } },
	{ MOD|ALT,				XK_i,      incrigaps,      {.i = +1 } },
	{ MOD|ALT|SHIFT,		XK_i,      incrigaps,      {.i = -1 } },
	{ MOD|ALT,				XK_o,      incrogaps,      {.i = +1 } },
	{ MOD|ALT|SHIFT,		XK_o,      incrogaps,      {.i = -1 } },
	{ MOD|ALT,				XK_6,      incrihgaps,     {.i = +1 } },
	{ MOD|ALT|SHIFT,		XK_6,      incrihgaps,     {.i = -1 } },
	{ MOD|ALT,				XK_7,      incrivgaps,     {.i = +1 } },
	{ MOD|ALT|SHIFT,		XK_7,      incrivgaps,     {.i = -1 } },
	{ MOD|ALT,				XK_8,      incrohgaps,     {.i = +1 } },
	{ MOD|ALT|SHIFT,		XK_8,      incrohgaps,     {.i = -1 } },
	{ MOD|ALT,				XK_9,      incrovgaps,     {.i = +1 } },
	{ MOD|ALT|SHIFT,		XK_9,      incrovgaps,     {.i = -1 } },
	{ MOD|ALT,				XK_0,      togglegaps,     {0} },
	{ MOD|ALT|SHIFT,		XK_0,      defaultgaps,    {0} },

	// Window Management -----------
	/* Murder */
    { MOD, 					XK_q, 						killclient, {0} }, // Kill window
    { MOD, 					XK_Escape, 					spawn, SHCMD("xkill") }, // xkill


	{ MOD,					XK_Tab,    view,           {0} },
	{ MOD,					XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MOD,					XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MOD,					XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MOD,					XK_u,      setlayout,      {.v = &layouts[11]} },
	{ MOD,					XK_space,  setlayout,      {0} },
	{ MOD|SHIFT,			XK_space,  togglefloating, {0} },
	{ MOD,					XK_0,      view,           {.ui = ~0 } },
	{ MOD|SHIFT,			XK_0,      tag,            {.ui = ~0 } },
	{ MOD,					XK_comma,  focusmon,       {.i = -1 } },
	{ MOD,					XK_period, focusmon,       {.i = +1 } },
	{ MOD|SHIFT,			XK_comma,  tagmon,         {.i = -1 } },
	{ MOD|SHIFT,			XK_period, tagmon,         {.i = +1 } },


	// Tags ------------------------------------------------------------------
	TAGKEYS(				XK_1,                      0)
	TAGKEYS(				XK_2,                      1)
	TAGKEYS(				XK_3,                      2)
	TAGKEYS(				XK_4,                      3)
	TAGKEYS(				XK_5,                      4)
	TAGKEYS(				XK_6,                      5)
	TAGKEYS(				XK_7,                      6)
	TAGKEYS(				XK_8,                      7)
	TAGKEYS(				XK_9,                      8)

	// DWM Session	-----------
    { MOD|CTRL,				XK_c,						quit, {0} }, // Quit DWM
    { MOD|SHIFT,			XK_r, 						quit, {1} }, // Restart DWM
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MOD,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MOD,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MOD,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MOD,         Button1,        tag,            {0} },
	{ ClkTagBar,            MOD,         Button3,        toggletag,      {0} },
};

