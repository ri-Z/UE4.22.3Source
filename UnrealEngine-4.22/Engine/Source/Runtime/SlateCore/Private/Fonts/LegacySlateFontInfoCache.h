// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/GCObject.h"
#include "Fonts/CompositeFont.h"

/**
 * Cache used to efficiently upgrade legacy FSlateFontInfo structs to use a composite font by reducing the amount of duplicate instances that are created
 */
class FLegacySlateFontInfoCache : public FGCObject, public TSharedFromThis<FLegacySlateFontInfoCache>
{
public:
	/**
	 * Context used to help debug font fallback requests
	 */
	struct FFallbackContext
	{
	public:
		FFallbackContext() = default;

		FFallbackContext(const FFontData* InFontData, const TCHAR InChar)
			: FontData(InFontData)
			, Char(InChar)
		{
		}

		FString ToString() const;

	private:
		const FFontData* FontData = nullptr;
		TCHAR Char = 0;
	};

	/**
	 * Get (or create) the singleton instance of this cache
	 */
	static FLegacySlateFontInfoCache& Get();

	/**
	 * Get (or create) an appropriate composite font from the legacy font name
	 */
	TSharedPtr<const FCompositeFont> GetCompositeFont(const FName& InLegacyFontName, const EFontHinting InLegacyFontHinting);

	/**
	 * Get (or create) the default font based on the current build configuration
	 */
	TSharedRef<const FCompositeFont> GetDefaultFont();

	/**
	 * Get (or create) the default system font
	 */
	TSharedPtr<const FCompositeFont> GetSystemFont();

	/**
	 * Is the localized fallback font available (can be controlled via a CVar).
	 */
	bool IsLocalizedFallbackFontAvailable() const;

	/**
	 * Get (or create) the culture specific fallback font
	 */
	const FFontData& GetLocalizedFallbackFontData(const FFallbackContext& InContext);

	/**
	 * Get the revision index of the currently active localized fallback font.
	 */
	uint16 GetLocalizedFallbackFontRevision() const;

	/**
	 * Is the last resort fallback font available (not all builds have it).
	 */
	bool IsLastResortFontAvailable() const;

	/**
	 * Get (or create) the last resort fallback font
	 */
	TSharedPtr<const FCompositeFont> GetLastResortFont();

	/**
	 * Get (or create) the last resort fallback font
	 */
	const FFontData& GetLastResortFontData(const FFallbackContext& InContext);

	// FGCObject interface
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

private:
	FLegacySlateFontInfoCache();

	/**
	 * Called after the active culture has changed
	 */
	void HandleCultureChanged();

	struct FLegacyFontKey
	{
		FLegacyFontKey()
			: Name()
			, Hinting(EFontHinting::Default)
		{
		}

		FLegacyFontKey(const FName& InName, const EFontHinting InHinting)
			: Name(InName)
			, Hinting(InHinting)
		{
		}

		bool operator==(const FLegacyFontKey& Other) const 
		{
			return Name == Other.Name && Hinting == Other.Hinting;
		}

		bool operator!=(const FLegacyFontKey& Other) const 
		{
			return !(*this == Other);
		}

		friend inline uint32 GetTypeHash(const FLegacyFontKey& Key)
		{
			uint32 Hash = 0;
			Hash = HashCombine(Hash, GetTypeHash(Key.Name));
			Hash = HashCombine(Hash, uint32(Key.Hinting));
			return Hash;
		}

		FName Name;
		EFontHinting Hinting;
	};

	TMap<FLegacyFontKey, TSharedPtr<const FCompositeFont>> LegacyFontNameToCompositeFont;
	TSharedPtr<const FCompositeFont> DefaultFont;
	TSharedPtr<const FCompositeFont> SystemFont;
	TSharedPtr<const FCompositeFont> LastResortFont;
	
	TSharedPtr<const FFontData> LocalizedFallbackFontData;
	TSharedPtr<const FFontData> LastResortFontData;

	TMap<FString, TSharedPtr<const FFontData>> AllLocalizedFallbackFontData;
	uint16 LocalizedFallbackFontRevision;
	uint16 LocalizedFallbackFontDataHistoryVersion;
	uint64 LocalizedFallbackFontFrameCounter;

	FCriticalSection LocalizedFallbackFontDataCS;
	FCriticalSection LastResortFontCS;
	FCriticalSection LastResortFontDataCS;

	FString LastResortFontPath;
	bool bIsLastResortFontAvailable;

	static TSharedPtr<FLegacySlateFontInfoCache> Singleton;
};
