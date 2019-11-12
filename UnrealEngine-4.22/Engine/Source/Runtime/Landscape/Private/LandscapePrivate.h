// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Stats/Stats.h"


LANDSCAPE_API DECLARE_LOG_CATEGORY_EXTERN(LogLandscape, Warning, All);
LANDSCAPE_API DECLARE_LOG_CATEGORY_EXTERN(LogLandscapeBP, Display, All);

/**
 * Landscape stats
 */
DECLARE_CYCLE_STAT_EXTERN(TEXT("Dynamic Draw Time"), STAT_LandscapeDynamicDrawTime, STATGROUP_Landscape, );
DECLARE_CYCLE_STAT_EXTERN(TEXT("Static Draw LOD Time"), STAT_LandscapeStaticDrawLODTime, STATGROUP_Landscape, );
DECLARE_CYCLE_STAT_EXTERN(TEXT("Render SetMesh Draw Time VS"), STAT_LandscapeVFDrawTimeVS, STATGROUP_Landscape, );
DECLARE_CYCLE_STAT_EXTERN(TEXT("Render SetMesh Draw Time PS"), STAT_LandscapeVFDrawTimePS, STATGROUP_Landscape, );
DECLARE_CYCLE_STAT_EXTERN(TEXT("Init View Custom Data"), STAT_LandscapeInitViewCustomData, STATGROUP_Landscape, );
DECLARE_CYCLE_STAT_EXTERN(TEXT("PostInit View Custom Data"), STAT_LandscapePostInitViewCustomData, STATGROUP_Landscape, );
DECLARE_CYCLE_STAT_EXTERN(TEXT("Compute Custom Mesh Batch LOD"), STAT_LandscapeComputeCustomMeshBatchLOD, STATGROUP_Landscape, );
DECLARE_CYCLE_STAT_EXTERN(TEXT("Compute Custom Shadow Mesh Batch LOD"), STAT_LandscapeComputeCustomShadowMeshBatchLOD, STATGROUP_Landscape, );

DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("Components Using SubSection DrawCall"), STAT_LandscapeComponentUsingSubSectionDrawCalls, STATGROUP_Landscape, );
DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("Tessellated Shadow Cascade"), STAT_LandscapeTessellatedShadowCascade, STATGROUP_Landscape, );
DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("Tessellated Components"), STAT_LandscapeTessellatedComponents, STATGROUP_Landscape, );
DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("Processed Triangles"), STAT_LandscapeTriangles, STATGROUP_Landscape, );
DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("Render Passes"), STAT_LandscapeComponentRenderPasses, STATGROUP_Landscape, );
DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("DrawCalls"), STAT_LandscapeDrawCalls, STATGROUP_Landscape, );

DECLARE_CYCLE_STAT_EXTERN(TEXT("Regenerate Procedural Heightmap (GameThread)"), STAT_LandscapeRegenerateProceduralHeightmaps, STATGROUP_Landscape, );
DECLARE_CYCLE_STAT_EXTERN(TEXT("Regenerate Procedural Heightmap (RenderThread)"), STAT_LandscapeRegenerateProceduralHeightmaps_RenderThread, STATGROUP_Landscape, );
DECLARE_CYCLE_STAT_EXTERN(TEXT("Resolve Procedural Heightmap"), STAT_LandscapeResolveProceduralHeightmap, STATGROUP_Landscape, );

DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("Regenerate Procedural Heightmap DrawCalls"), STAT_LandscapeRegenerateProceduralHeightmapsDrawCalls, STATGROUP_Landscape, );

DECLARE_MEMORY_STAT_EXTERN(TEXT("Vertex Mem"), STAT_LandscapeVertexMem, STATGROUP_Landscape, );
DECLARE_MEMORY_STAT_EXTERN(TEXT("Occluder Mem"), STAT_LandscapeOccluderMem, STATGROUP_Landscape, );
DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("Component Mem"), STAT_LandscapeComponentMem, STATGROUP_Landscape, );