#pragma once
#include <glm/vec2.hpp>
#include <glm/mat4x4.hpp>

#include <vector>
#include <list>

#include "Terrain/Terrain.h"

#include "Renderer/GlStateManager.h"
#include "EntityRenderer.h"
#include "TerrainRenderer.h"

#include "MathUtils.h"
#include "Toolkit.h"

class ResourceMgr;

class MasterRenderer
{
private:
	std::vector<Light> lights;
	EntityRenderer entityRenderer;
	TerrainRenderer terrainRenderer;

	EntityRenderer::Batches batchedEntities;
	std::vector<Terrain*> terrains;

	bool wireframe, needsToUpdateWireframe;
	
	float timePassed;

	GlStateManager gl;
public:
	MasterRenderer();

	void addEntity(Entity& entity);
	void processTerrain(Terrain& terrain);

	void prepare() const;
	void render(float partialTicks, const Camera& camera);

	void toggleWireframeView() { wireframe = !wireframe; needsToUpdateWireframe = true; }
	
	inline const EntityRenderer::Batches& getEntityBatches() const { return batchedEntities; }
	inline EntityRenderer::Batches& getEntityBatches() { return batchedEntities; }

	inline const std::vector<Light>& getLights() const { return lights; }
	inline std::vector<Light>& getLights() { return lights; }

	inline GlStateManager& getGl() { return gl; }
	inline const GlStateManager& getGl() const { return gl; }

	inline EntityRenderer& getEntityRenderer() { return entityRenderer; }
	inline const EntityRenderer& getEntityRenderer() const { return entityRenderer; }

	inline TerrainRenderer& getTerrainRenderer() { return terrainRenderer; }
	inline const TerrainRenderer& getTerrainRenderer() const { return terrainRenderer; }
};
