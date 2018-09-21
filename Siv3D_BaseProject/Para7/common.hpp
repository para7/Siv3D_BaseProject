#pragma once

#include <Siv3D.hpp>

struct scoredata
{
	int score;
	Date date;
};

struct Common
{
private:
	const String filename;
	
public:

	Common()
		: filename(L"scoredata")
	{

		BinaryReader reader(filename);
		if (reader)
		{
			reader.read(norma_score.score);
			reader.read(norma_score.date);
			reader.read(perfect_score.score);
			reader.read(perfect_score.date);
			reader.close();
		}
		else
		{
			norma_score = { 0, DateTime::Now() };
			perfect_score = { 0, DateTime::Now() };
		}
	}

	~Common()
	{
		BinaryWriter writer(filename);
		if (writer)
		{
			writer.write(norma_score.score);
			writer.write(norma_score.date);
			writer.write(perfect_score.score);
			writer.write(perfect_score.date);
			writer.close();
		}
	}

	FileArchive arc{ L"/1001" };

	int score;
	scoredata norma_score, perfect_score;
};