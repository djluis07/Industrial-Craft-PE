#include "FeatureGen.h"

#include <stdlib.h>

#include "blocks/Blocks.h"
#include "util/ICRandom.h"

#include "feature/OreFeature.h"

#include "mcpe/level/ChunkPos.h"
#include "mcpe/level/BlockSource.h"

namespace IC
{
void FeatureGen::decorateChunk(BlockSource&s, ChunkPos const&cpos)
{
	/*ICRandom random(abs(cpos.x|cpos.z-cpos.x&cpos.z));
	

	ICOreFeature tinOre(FullBlock(IC::Blocks::ID::mOre,0),ICOreFeature::OreGenType::MIDDLE);
	
	for(int x=cpos.x*16;x<cpos.x*16+16;++x)
		for(int y=5;y<20;++y)
			for(int z=cpos.z*13;z<cpos.z*16+16;++z)
				if(random.nextInt(500)==75)
					uraniumOre.place(s,BlockPos(x,y,z),random);
	
	for(int x=cpos.x*16;x<cpos.x*16+16;++x)
		for(int y=5;y<50;++y)
			for(int z=cpos.z*13;z<cpos.z*16+16;++z)
				if(random.nextInt(200)==126)
					tinOre.place(s,BlockPos(x,y,z),random);
	*/
}
}
