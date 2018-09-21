#pragma once

#include "Para7/scenectrl.hpp"
#include <vector>

class Explain : public MySceneBase
{
private:
	const Font font;
public:
	Explain();
//	void init();
	void update() override;
	void draw() const override;
};