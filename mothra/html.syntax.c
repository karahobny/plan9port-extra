#include <u.h>
#include <libc.h>
#include <draw.h>
#include <event.h>
#include <panel.h>
#include "mothra.h"
#include "html.h"
Tag tag[]={
[Tag_comment]	"!--",		NOEND,
[Tag_a]		"a",		END,
[Tag_address]	"address",	END,
[Tag_b]		"b",		END,
[Tag_base]	"base",		NOEND,
[Tag_blockquot]	"blockquote",	END,
[Tag_body]	"body",		END,	/* OPTEND */
[Tag_br]	"br",		NOEND,
[Tag_center]	"center",	END,
[Tag_cite]	"cite",		END,
[Tag_code]	"code",		END,
[Tag_dd]	"dd",		NOEND,	/* OPTEND */
[Tag_dfn]	"dfn",		END,
[Tag_dir]	"dir",		END,
[Tag_dl]	"dl",		END,
[Tag_dt]	"dt",		NOEND,	/* OPTEND */
[Tag_em]	"em",		END,
[Tag_font]	"font",		END,
[Tag_form]	"form",		END,
[Tag_h1]	"h1",		END,
[Tag_h2]	"h2",		END,
[Tag_h3]	"h3",		END,
[Tag_h4]	"h4",		END,
[Tag_h5]	"h5",		END,
[Tag_h6]	"h6",		END,
[Tag_head]	"head",		END,	/* OPTEND */
[Tag_hr]	"hr",		NOEND,
[Tag_html]	"html",		END,	/* OPTEND */
[Tag_i]		"i",		END,
[Tag_input]	"input",	NOEND,
[Tag_img]	"img",		NOEND,
[Tag_isindex]	"isindex",	NOEND,
[Tag_kbd]	"kbd",		END,
[Tag_key]	"key",		END,
[Tag_li]	"li",		NOEND,	/* OPTEND */
[Tag_link]	"link",		NOEND,
[Tag_listing]	"listing",	END,
[Tag_menu]	"menu",		END,
[Tag_meta]	"meta",		NOEND,
[Tag_nextid]	"nextid",	NOEND,
[Tag_ol]	"ol",		END,
[Tag_option]	"option",	NOEND,	/* OPTEND */
[Tag_p]		"p",		NOEND,	/* OPTEND */
[Tag_plaintext]	"plaintext",	NOEND,
[Tag_pre]	"pre",		END,
[Tag_samp]	"samp",		END,
[Tag_script]	"script",	END,
[Tag_select]	"select",	END,
[Tag_strong]	"strong",	END,
[Tag_table]		"table",	END,
[Tag_td]		"td",		END,
[Tag_textarea]	"textarea",	END,
[Tag_title]	"title",	END,
[Tag_tr]	"tr",		END,
[Tag_tt]	"tt",		END,
[Tag_u]		"u",		END,
[Tag_ul]	"ul",		END,
[Tag_var]	"var",		END,
[Tag_xmp]	"xmp",		END,
[Tag_frame]	"frame",	NOEND,
[Tag_end]	0,		ERR,
};
Entity pl_entity[]={
"AElig",	L'Æ',
"Aacute",	L'Á',
"Acirc",	L'Â',
"Agrave",	L'À',
"Alpha",	L'Α',
"Aring",	L'Å',
"Atilde",	L'Ã',
"Auml",	L'Ä',
"Beta",	L'Β',
"Ccedil",	L'Ç',
"Chi",	L'Χ',
"Dagger",	L'‡',
"Delta",	L'Δ',
"ETH",	L'Ð',
"Eacute",	L'É',
"Ecirc",	L'Ê',
"Egrave",	L'È',
"Epsilon",	L'Ε',
"Eta",	L'Η',
"Euml",	L'Ë',
"Gamma",	L'Γ',
"Iacute",	L'Í',
"Icirc",	L'Î',
"Igrave",	L'Ì',
"Iota",	L'Ι',
"Iuml",	L'Ï',
"Kappa",	L'Κ',
"Lambda",	L'Λ',
"Mu",	L'Μ',
"Ntilde",	L'Ñ',
"Nu",	L'Ν',
"OElig",	L'Œ',
"Oacute",	L'Ó',
"Ocirc",	L'Ô',
"Ograve",	L'Ò',
"Omega",	L'Ω',
"Omicron",	L'Ο',
"Oslash",	L'Ø',
"Otilde",	L'Õ',
"Ouml",	L'Ö',
"Phi",	L'Φ',
"Pi",	L'Π',
"Prime",	L'″',
"Psi",	L'Ψ',
"Rho",	L'Ρ',
"Scaron",	L'Š',
"Sigma",	L'Σ',
"THORN",	L'Þ',
"Tau",	L'Τ',
"Theta",	L'Θ',
"Uacute",	L'Ú',
"Ucirc",	L'Û',
"Ugrave",	L'Ù',
"Upsilon",	L'Υ',
"Uuml",	L'Ü',
"Xi",	L'Ξ',
"Yacute",	L'Ý',
"Yuml",	L'Ÿ',
"Zeta",	L'Ζ',
"aacute",	L'á',
"acirc",	L'â',
"acute",	L'´',
"aelig",	L'æ',
"agrave",	L'à',
"alefsym",	L'ℵ',
"alpha",	L'α',
"amp",	L'&',
"and",	L'∧',
"ang",	L'∠',
"aring",	L'å',
"asymp",	L'≈',
"atilde",	L'ã',
"auml",	L'ä',
"bdquo",	L'„',
"beta",	L'β',
"brvbar",	L'¦',
"bull",	L'•',
"cap",	L'∩',
"ccedil",	L'ç',
"cdots",	L'⋯',
"cedil",	L'¸',
"cent",	L'¢',
"chi",	L'χ',
"circ",	L'ˆ',
"clubs",	L'♣',
"cong",	L'≅',
"copy",	L'©',
"crarr",	L'↵',
"cup",	L'∪',
"curren",	L'¤',
"dArr",	L'⇓',
"dagger",	L'†',
"darr",	L'↓',
"ddots",	L'⋱',
"deg",	L'°',
"delta",	L'δ',
"diams",	L'♦',
"divide",	L'÷',
"eacute",	L'é',
"ecirc",	L'ê',
"egrave",	L'è',
"emdash",	L'—',
"empty",	L'∅',
"emsp",	L' ',
"endash",	L'–',
"ensp",	L' ',
"epsilon",	L'ε',
"equiv",	L'≡',
"eta",	L'η',
"eth",	L'ð',
"euml",	L'ë',
"euro",	L'€',
"exist",	L'∃',
"fnof",	L'ƒ',
"forall",	L'∀',
"frac12",	L'½',
"frac14",	L'¼',
"frac34",	L'¾',
"frasl",	L'⁄',
"gamma",	L'γ',
"ge",	L'≥',
"gt",	L'>',
"hArr",	L'⇔',
"harr",	L'↔',
"hearts",	L'♥',
"hellip",	L'…',
"iacute",	L'í',
"icirc",	L'î',
"iexcl",	L'¡',
"igrave",	L'ì',
"image",	L'ℑ',
"infin",	L'∞',
"int",	L'∫',
"iota",	L'ι',
"iquest",	L'¿',
"isin",	L'∈',
"iuml",	L'ï',
"kappa",	L'κ',
"lArr",	L'⇐',
"lambda",	L'λ',
"lang",	L'〈',
"laquo",	L'«',
"larr",	L'←',
"lceil",	L'⌈',
"ldots",	L'…',
"ldquo",	L'“',
"le",	L'≤',
"lfloor",	L'⌊',
"lowast",	L'∗',
"loz",	L'◊',
"lrm",	L'‎',
"lsaquo",	L'‹',
"lsquo",	L'‘',
"lt",	L'<',
"macr",	L'¯',
"mdash",	L'—',
"micro",	L'µ',
"middot",	L'·',
"minus",	L'−',
"mu",	L'μ',
"nabla",	L'∇',
"nbsp",	L' ',
"ndash",	L'–',
"ne",	L'≠',
"ni",	L'∋',
"not",	L'¬',
"notin",	L'∉',
"nsub",	L'⊄',
"ntilde",	L'ñ',
"nu",	L'ν',
"oacute",	L'ó',
"ocirc",	L'ô',
"oelig",	L'œ',
"ograve",	L'ò',
"oline",	L'‾',
"omega",	L'ω',
"omicron",	L'ο',
"oplus",	L'⊕',
"or",	L'∨',
"ordf",	L'ª',
"ordm",	L'º',
"oslash",	L'ø',
"otilde",	L'õ',
"otimes",	L'⊗',
"ouml",	L'ö',
"para",	L'¶',
"part",	L'∂',
"permil",	L'‰',
"perp",	L'⊥',
"phi",	L'φ',
"pi",	L'π',
"piv",	L'ϖ',
"plusmn",	L'±',
"pound",	L'£',
"prime",	L'′',
"prod",	L'∏',
"prop",	L'∝',
"psi",	L'ψ',
"quad",	L' ',
"quot",	L'"',
"rArr",	L'⇒',
"radic",	L'√',
"rang",	L'〉',
"raquo",	L'»',
"rarr",	L'→',
"rceil",	L'⌉',
"rdquo",	L'”',
"real",	L'ℜ',
"reg",	L'®',
"rfloor",	L'⌋',
"rho",	L'ρ',
"rlm",	L'‏',
"rsaquo",	L'›',
"rsquo",	L'’',
"sbquo",	L'‚',
"scaron",	L'š',
"sdot",	L'⋅',
"sect",	L'§',
"shy",	L'­',
"sigma",	L'σ',
"sigmaf",	L'ς',
"sim",	L'∼',
"sp",	L' ',
"spades",	L'♠',
"sub",	L'⊂',
"sube",	L'⊆',
"sum",	L'∑',
"sup",	L'⊃',
"sup1",	L'¹',
"sup2",	L'²',
"sup3",	L'³',
"supe",	L'⊇',
"szlig",	L'ß',
"tau",	L'τ',
"there4",	L'∴',
"theta",	L'θ',
"thetasym",	L'ϑ',
"thinsp",	L' ',
"thorn",	L'þ',
"tilde",	L'˜',
"times",	L'×',
"trade",	L'™',
"uArr",	L'⇑',
"uacute",	L'ú',
"uarr",	L'↑',
"ucirc",	L'û',
"ugrave",	L'ù',
"uml",	L'¨',
"upsih",	L'ϒ',
"upsilon",	L'υ',
"uuml",	L'ü',
"varepsilon",	L'∈',
"varphi",	L'ϕ',
"varpi",	L'ϖ',
"varrho",	L'ϱ',
"vdots",	L'⋮',
"vsigma",	L'ς',
"vtheta",	L'ϑ',
"weierp",	L'℘',
"xi",	L'ξ',
"yacute",	L'ý',
"yen",	L'¥',
"yuml",	L'ÿ',
"zeta",	L'ζ',
"zwj",	L'‍',
"zwnj",	L'‌',
};
int pl_entities = nelem(pl_entity);
