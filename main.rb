require './FeederSystem.rb'

system = FeederSystem.new

# Tare scales
system.repository.tare
system.bowls[0].tare
system.bowls[1].tare

# Fill repo and bowls
system.repository.scale.load_sensor.value = 185
system.bowls[0].scale.load_sensor.value = 10
system.bowls[1].scale.load_sensor.value = 10

# Set maximums
system.repository.set_max
system.bowls[0].set_max
system.bowls[1].set_max

# Loop
system.start_timer