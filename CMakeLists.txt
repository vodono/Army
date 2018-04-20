cmake_minimum_required(VERSION 3.9)

project(Army)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(testing
        tests/main.cpp

        state/State.cpp
        tests/test_state.cpp


        unitTypes/UnitTypes.cpp
        ability/Ability.cpp
        unit/Unit.cpp
        tests/test_unit.cpp

        ability/DefaultAbility.cpp
        unit/Soldier.cpp
        tests/test_soldier.cpp

        ability/RogueAbility.cpp
        unit/Rogue.cpp
        tests/test_rogue.cpp

        unit/Berserker.cpp
        tests/test_berserker.cpp

        ability/VampireAbility.cpp
        unit/Vampire.cpp
        tests/test_vampire.cpp

        ability/WerewolfAbility.cpp
        state/WerewolfState.cpp
        unit/Werewolf.cpp
        tests/test_werewolf.cpp

        state/MagicState.cpp
        tests/test_magicState.cpp

        spell/Spell.cpp
        magicAbility/MagicAbility.cpp
        spellcaster/SpellCaster.cpp

        spell/FireBall.cpp
        spell/Lightning.cpp
        spell/Inferno.cpp
        spell/Heal.cpp
        spell/Pray.cpp
        spell/MagicBook.cpp

        magicAbility/WizardMagicAbility.cpp
        spellcaster/Wizard.cpp
        tests/test_wizard.cpp

        magicAbility/HealerMagicAbility.cpp
        spellcaster/Healer.cpp
        tests/test_healer.cpp

        magicAbility/PriestMagicAbility.cpp
        spellcaster/Priest.cpp
        tests/test_priest.cpp

        ability/DemonAbility.cpp
        unit/Demon.cpp
        magicAbility/WarlockMagicAbility.cpp
        spellcaster/Warlock.cpp
        tests/test_warlock.cpp

        )

#add_executable(draft_main
#        draft_main.cpp
#        unit/Unit.cpp
#        state/State.cpp
#        unitTypes/UnitTypes.cpp
#        ability/Ability.cpp
#        ability/DefaultAbility.cpp
#        unit/Soldier.cpp
#        state/MagicState.cpp
#
#        spell/Spell.cpp
#        magicAbility/MagicAbility.cpp
#        spellcaster/SpellCaster.cpp
#
#        spell/FireBall.cpp
#        spell/Lightning.cpp
#        spell/Inferno.cpp
#        spell/Heal.cpp
#        spell/Pray.cpp
#        spell/MagicBook.cpp
#
#        magicAbility/WizardMagicAbility.cpp
#        spellcaster/Wizard.cpp
#        spellcaster/Healer.cpp spellcaster/Healer.h magicAbility/HealerMagicAbility.cpp magicAbility/HealerMagicAbility.h spellcaster/Priest.cpp spellcaster/Priest.h magicAbility/PriestMagicAbility.cpp magicAbility/PriestMagicAbility.h)