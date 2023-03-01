require "keybow"
require "snippets/win_snippets"
-- Keybow MINI --

function setup()
    keybow.use_mini()
    keybow.auto_lights(false)
    keybow.clear_lights()
end

-- Key mappings --

function handle_minikey_00(pressed)
    keybow.set_key("0", pressed)
    if pressed then
        keybow.set_pixel(1, 0, 255, 0)
        keybow.set_modifier(keybow.LEFT_META,keybow.KEY_DOWN)
        keybow.set_modifier(keybow.LEFT_SHIFT,keybow.KEY_DOWN)
        keybow.tap_key("o",pressed)
        keybow.set_modifier(keybow.LEFT_SHIFT,keybow.KEY_UP)
        keybow.set_modifier(keybow.LEFT_META,keybow.KEY_UP)
    else
        keybow.set_pixel(0, 255, 0, 0)
    end
end

function handle_minikey_01(pressed) --Micro mute
    keybow.set_key("1", pressed)
    if pressed then
        keybow.set_pixel(1, 0, 255, 0)
        keybow.set_modifier(keybow.LEFT_META,keybow.KEY_DOWN)
        keybow.set_modifier(keybow.LEFT_SHIFT,keybow.KEY_DOWN)
        keybow.tap_key("a",pressed)
        keybow.set_modifier(keybow.LEFT_SHIFT,keybow.KEY_UP)
        keybow.set_modifier(keybow.LEFT_META,keybow.KEY_UP)
    else
        keybow.set_pixel(1, 0, 0, 255)
    end
end

function handle_minikey_02(pressed) -- Zombie Ipsum
    if pressed then
        keybow.text([[
Zombie ipsum reversus ab viral inferno, nam rick grimes malum cerebro. De
carne lumbering animata corpora quaeritis. Summus brains sit​​, morbo vel
maleficia? De apocalypsi gorger omero undead survivor dictum mauris. Hi
mindless mortuis soulless creaturas, imo evil stalking monstra adventus resi
dentevil vultus comedat cerebella viventium. Qui animated corpse, cricket bat
max brucks terribilem incessu zomby. The voodoo sacerdos flesh eater, suscitat
mortuos comedere carnem virus. Zonbi tattered for solum oculi eorum defunctis
go lum cerebro. Nescio brains an Undead zombies. Sicut malus putrid voodoo
horror. Nigh tofth eliv ingdead.
]])
    end
end