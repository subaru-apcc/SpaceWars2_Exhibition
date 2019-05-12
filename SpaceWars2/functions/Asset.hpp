#pragma once
#include <Siv3D.hpp>

enum SmartUISize {
	S12 = 12,
	S28 = 28,
	S32 = 32
};
namespace SmartUI {
	extern Array<SmartUISize> size;
	// register all
	bool Register();
	// Returns: Font
	Font GetFont(SmartUISize _size);
}

enum SmartBSize {
	Sb12 = 12,
};
namespace SmartB {
	extern Array<SmartBSize> size;
	// register all
	bool Register();
	// Returns: Font
	Font GetFont(SmartBSize _size);
}

enum CicaRSize {
	C12 = 12,
	C18 = 18,
	C32 = 32
};
namespace CicaR {
	extern Array<CicaRSize> size;
	// register all
	bool Register();
	// Returns: Font
	Font GetFont(CicaRSize _size);
}

enum LettersSize {
	L7  = 7,
	L10 = 10,
	L12 = 12,
	L18 = 18,
	L32 = 32
};
namespace Letters {
	extern Array<LettersSize> size;
	// register all
	bool Register();
	// Returns: Font
	Font GetFont(LettersSize _size);
}