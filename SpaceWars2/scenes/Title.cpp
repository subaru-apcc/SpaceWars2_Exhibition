#include "Title.hpp"

int Title::selecting = 0;

void Title::init() {
	Data::LPlayer.init(Vec2(80, Config::HEIGHT / 2), true);  //円の半径
	Data::RPlayer.init(Vec2(1200, Config::HEIGHT / 2), false); //WIDTH-円の半径
	Data::LPlayer.initSkill();
	Data::RPlayer.initSkill();
}

void Title::update(){
	changeScene(Debug::InputFnKey(), 100);

	if (Data::KeySelectUp.repeat(20, true) && selecting > 0) {
		--selecting;
		SoundAsset(L"cursor1").setVolume(Config::MASTER_VOLUME * Config::CURSOR_VOLUME);
		SoundAsset(L"cursor1").playMulti();
	}
	if (Data::KeySelectDown.repeat(20, true) && selecting < 1) {
		++selecting;
		SoundAsset(L"cursor1").setVolume(Config::MASTER_VOLUME * Config::CURSOR_VOLUME);
		SoundAsset(L"cursor1").playMulti();
	}

	if (Data::KeyEnter.repeat(20)) {
		SoundAsset(L"click1").setVolume(Config::MASTER_VOLUME * Config::CURSOR_VOLUME);
		SoundAsset(L"click1").play();
		switch(selecting) {
		case 0:
			changeScene(L"ControlGuidance", 500);
			break;

		case 1:
			changeScene(L"SkillSelect", 500);
			break;

		case 2:
			changeScene(L"License", 500);
			break;

		case 3:
			System::Exit();
			break;

		default:
			LOG_ERROR(L"Title画面で意図しない値 \"", selecting, L"\" が参照されました。");
		}
	}

}

void Title::draw() const {
	TextureAsset(L"background").resize(Window::Size()).draw();
	TextureAsset(L"title-logo").drawAt(Window::Center().x + 50, 150);

	Circle(1180, 1080, 760).drawFrame(5, 5, Color(L"#00bfff"));

	const String name[4] = { L"START", L"GAME", L"LICENSE", L"EXIT" };
	for (auto i : step(2)) {
		TextureAsset(i == selecting ? L"title-button" : L"title-button-hidden").draw(950, 400 + 70 * i);
		SmartUI::Get(S28)(name[i]).draw({ 980, 398 + 70 * i }, i == selecting ? ColorF(L"#fff") : ColorF(L"#ccc"));
	}

	for (int i = 2; i < 4; i++) {
		TextureAsset(L"title-button-hidden").draw(950, 400 + 70 * i, ColorF(L"#fff").setAlpha(0.4));
		SmartUI::Get(S28)(name[i]).draw({ 980, 398 + 70 * i }, ColorF(L"#ccc").setAlpha(0.4));
	}

	TextureAsset(L"license-s").draw(0, 260);

	Rect(0, 690, 220, 30).draw(ColorF(L"#000").setAlpha(0.5));
	CicaR::Get(C12)(Config::VERSION, L" / ", Config::VER_NUM).draw({ 10, 695 });
}
