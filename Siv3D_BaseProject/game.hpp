#pragma once

#include "Para7//Para7Utilities.hpp"

class Game : public MySceneBase
{
public:
	void init() override;
	void update() override;
	void draw() const override;
};