### Plant tracker
### Need to do: Have ADC pull soil info, check it against parameters, water plant by activating a water pump electronically, for some amount of time. Quiet itself into sleep mode, check again ### every day. Upgrades include texting mom when it waters or sending a picture through email.

class Plants(object):
    '''Base plants class.
    This class will track plants' information: soil moisture, temperature and sunlight.  '''
    def __init__(self, t, wtimes, moisture_level, light_level):
        """Initialization """
        self.t = t
        self.wtimes = wtimes
        self.status_points = 10
        self.moisture_level = moisture_level
        self.light_level = light_level

    def __str__(self):
        """String update of plant status"""
        return "This plant is a %s , I was watered %s times, and I have a status of %s" %(self.t, self.wtimes, self.status_points)

    def update_sensors(self):
        """Plan: log reasonable last data, with "reasonable" being decided by the user. This will give option for graphing and visuals to be eventually exported.
        storage setup: http://www.makeuseof.com/tag/how-to-add-usb-storage-to-the-raspberry-pi/"""
        return [self.moisture_level, self.light_level]

    def update_watered(self):
        """Updates how many times it was watered, without time (for now)
        Future plan: time the length between waterings"""
        self.wtimes = self.wtimes + 1
        return self.wtimes

    def status(self): #Purely for the user. Like the Nissan Leaf's status leaves
        """Point status (0-10, 10 being great) of plant health.
        About to be watered/little dry will lower plant health status by a point.
        Water tank out/low will lower it by 2.
        Sensor malfunction will result in 0

        Needs to be implemented still"""
        return self.status_points

Caesar = Plants('fern', 4, 4, 5)
print Caesar

Caesar.update_watered()
print Caesar
