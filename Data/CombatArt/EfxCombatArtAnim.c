// SPDX-License-Identifier: GPL-2.0-only

#include "common-chax.h"
#include "efx-anim.h"
#include "skill-system.h"
#include "constants/efx-skills.h"
#include "constants/combat-arts.h"

const u8 EfxCombatArtAnimPriority[0x100] = {
    [CID_WrathStrike] = EFX_PRIORITY_HIGHHIGH,
    [CID_Grounder] = EFX_PRIORITY_HIGHHIGH,
    [CID_Soulblade] = EFX_PRIORITY_HIGHHIGH,
    [CID_BaneOfMonsters] = EFX_PRIORITY_HIGHHIGH,
    [CID_Sunder] = EFX_PRIORITY_HIGHHIGH,
    [CID_Hexblade] = EFX_PRIORITY_HIGHHIGH,
    [CID_HazeSlice] = EFX_PRIORITY_HIGHHIGH,
    [CID_FinesseBlade] = EFX_PRIORITY_HIGHHIGH,
    [CID_Assassinate] = EFX_PRIORITY_HIGHHIGH,
    [CID_FoudroyantStrike] = EFX_PRIORITY_HIGHHIGH,
    [CID_TempestLance] = EFX_PRIORITY_HIGHHIGH,
    [CID_Knightkneeler] = EFX_PRIORITY_HIGHHIGH,
    [CID_ShatterSlash] = EFX_PRIORITY_HIGHHIGH,
    [CID_MonsterPiercer] = EFX_PRIORITY_HIGHHIGH,
    [CID_SwiftStrikes] = EFX_PRIORITY_HIGHHIGH,
    [CID_FrozenLance] = EFX_PRIORITY_HIGHHIGH,
    [CID_Vengeance] = EFX_PRIORITY_HIGHHIGH,
    [CID_LanceJab] = EFX_PRIORITY_HIGHHIGH,
    [CID_Smash] = EFX_PRIORITY_HIGHHIGH,
    [CID_HelmSplitter] = EFX_PRIORITY_HIGHHIGH,
    [CID_MonsterBreaker] = EFX_PRIORITY_HIGHHIGH,
    [CID_FocusedStrike] = EFX_PRIORITY_HIGHHIGH,
    [CID_WildAbandon] = EFX_PRIORITY_HIGHHIGH,
    [CID_Spike] = EFX_PRIORITY_HIGHHIGH,
    [CID_DiamondAxe] = EFX_PRIORITY_HIGHHIGH,
    [CID_LightningAxe] = EFX_PRIORITY_HIGHHIGH,
    [CID_ArmoredStrike] = EFX_PRIORITY_HIGHHIGH,
    [CID_WarMasterStrike] = EFX_PRIORITY_HIGHHIGH,
    [CID_FlickeringFlower] = EFX_PRIORITY_HIGHHIGH,
    [CID_CurvedShot] = EFX_PRIORITY_HIGHHIGH,
    [CID_Deadeye] = EFX_PRIORITY_HIGHHIGH,
    [CID_Encloser] = EFX_PRIORITY_HIGHHIGH,
    [CID_EncloserPlus] = EFX_PRIORITY_HIGHHIGH,
    [CID_MonsterBlast] = EFX_PRIORITY_HIGHHIGH,
    [CID_SchismShot] = EFX_PRIORITY_HIGHHIGH,
    [CID_BreakShot] = EFX_PRIORITY_HIGHHIGH,
    [CID_BreakShotPlus] = EFX_PRIORITY_HIGHHIGH,
    [CID_WaningShotPlus] = EFX_PRIORITY_HIGHHIGH,
    [CID_HuntersVolley] = EFX_PRIORITY_HIGHHIGH,
    [CID_Galeforce] = EFX_PRIORITY_HIGHHIGH,
    [CID_Gamble] = EFX_PRIORITY_HIGHHIGH,
    [CID_Detonate] = EFX_PRIORITY_HIGHHIGH,
};

struct EfxAnimConf const *const EfxCombatArtAnims[0x100] = {
    [CID_WrathStrike] = &EfxSkillCombat,
    [CID_Grounder] = &EfxSkillCombat,
    [CID_Soulblade] = &EfxSkillCombat,
    [CID_BaneOfMonsters] = &EfxSkillCombat,
    [CID_Sunder] = &EfxSkillCombat,
    [CID_Hexblade] = &EfxSkillCombat,
    [CID_HazeSlice] = &EfxSkillCombat,
    [CID_FinesseBlade] = &EfxSkillCombat,
    [CID_Assassinate] = &EfxSkillCombat,
    [CID_FoudroyantStrike] = &EfxSkillCombat,
    [CID_TempestLance] = &EfxSkillCombat,
    [CID_Knightkneeler] = &EfxSkillCombat,
    [CID_ShatterSlash] = &EfxSkillCombat,
    [CID_MonsterPiercer] = &EfxSkillCombat,
    [CID_SwiftStrikes] = &EfxSkillCombat,
    [CID_FrozenLance] = &EfxSkillCombat,
    [CID_Vengeance] = &EfxSkillCombat,
    [CID_LanceJab] = &EfxSkillCombat,
    [CID_Smash] = &EfxSkillCombat,
    [CID_HelmSplitter] = &EfxSkillCombat,
    [CID_MonsterBreaker] = &EfxSkillCombat,
    [CID_FocusedStrike] = &EfxSkillCombat,
    [CID_WildAbandon] = &EfxSkillCombat,
    [CID_Spike] = &EfxSkillCombat,
    [CID_DiamondAxe] = &EfxSkillCombat,
    [CID_LightningAxe] = &EfxSkillCombat,
    [CID_ArmoredStrike] = &EfxSkillCombat,
    [CID_WarMasterStrike] = &EfxSkillCombat,
    [CID_FlickeringFlower] = &EfxSkillCombat,
    [CID_CurvedShot] = &EfxSkillCombat,
    [CID_Deadeye] = &EfxSkillCombat,
    [CID_Encloser] = &EfxSkillCombat,
    [CID_EncloserPlus] = &EfxSkillCombat,
    [CID_MonsterBlast] = &EfxSkillCombat,
    [CID_SchismShot] = &EfxSkillCombat,
    [CID_BreakShot] = &EfxSkillCombat,
    [CID_BreakShotPlus] = &EfxSkillCombat,
    [CID_WaningShotPlus] = &EfxSkillCombat,
    [CID_HuntersVolley] = &EfxSkillCombat,
    [CID_Galeforce] = &EfxSkillCombat,
    [CID_Gamble] = &EfxSkillCombat,
    [CID_Detonate] = &EfxSkillCombat,
};
