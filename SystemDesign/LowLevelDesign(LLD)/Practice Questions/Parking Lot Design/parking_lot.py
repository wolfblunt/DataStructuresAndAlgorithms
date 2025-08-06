class Solution:
    def __init__(self):
        self.helper = None
        self.parking = []
        self.floors = 0
        self.rows = 0
        self.columns = 0

        self.empty_spots = {}  # (floor, vehicleType : set(row, col))
        self.free_counts = {}  # (floor, vehicleType): int

        self.spot_to_vehicle = {}  # (vehicleType, vehicleNumber, ticketId)

        self.lookup = {}

    def init(self, helper, parking):
        self.helper = helper
        self.parking = parking
        self.floors = len(parking)
        self.rows = len(parking[0])
        self.columns = len(parking[0][0])
        self.empty_spots.clear()
        self.free_counts.clear()

        for floor in range(self.floors):
            for row in range(self.rows):
                for col in range(self.columns):
                    typ = parking[floor][row][col]
                    if typ == 2 or typ == 4:
                        self.empty_spots.setdefault((floor, typ), set()).add((row, col))
                        self.free_counts[(floor, typ)] = self.free_counts.get((floor, typ), 0) + 1

        self.spot_to_vehicle.clear()
        self.lookup.clear()

    def _format_spotid(self, floor, row, column):
        return f"{floor}-{row}-{column}"

    def park(self, vehicleType, vehicleNumber, ticketId, parkingStrategy):
        assigned = None
        if parkingStrategy == 0:
            for floor in range(self.floors):
                spots = self.empty_spots.get((floor, vehicleType), set())
                if spots:
                    row, col = min(spots)
                    assigned = (floor, row, col)
                    break

        elif parkingStrategy == 1:
            max_free = -1
            best_floors = []
            for floor in range(self.floors):
                count = self.free_count.get((floor, vehicleType), 0)
                if count > max_free:
                    max_free = count
                    best_floors = [floor]
                elif count == max_free:
                    best_floors.append(floor)

            for floor in best_floors:
                spots = self.empty_spots.get((floor, vehicleType), set())
                if spots:
                    row, col = min(spots)
                    assigned = (floor, row, col)
                    break

        if assigned is None:
            return ""

        floor, row, col = assigned
        spotId = self._format_spotid(floor, row, col)
        self.empty_spots[(floor, vehicleType)].remove((row, col))
        self.free_counts[(floor, vehicleType)] -= 1
        self.spot_to_vehicle[spotId] = (vehicleType, vehicleNumber, ticketId)
        self.lookup[vehicleNumber] = spotId
        self.lookup[ticketId] = spotId
        return spotId

    def removeVehicle(self, spotId):
        vehicleInfo = self.spot_to_vehicle.get(spotId, None)
        if not vehicleInfo:
            return False

        vehicleType, vehicleNumber, ticketId = vehicleInfo
        try:
            floor, row, col = map(int, spotId.split('-'))
        except:
            return False

        self.empty_spots.setdefault((floor, vehicleType), set()).add((row, col))
        self.free_counts[(floor, vehicleType)] = self.free_counts.get((floor, vehicleType), 0) + 1
        del self.spot_to_vehicle[spotId]
        if vehicleNumber in self.lookup:
            del self.lookup[vehicleNumber]
        if ticketId in self.lookup:
            del self.lookup[ticketId]

        return True

    def searchVehicle(self, query):
        return self.lookup.get(query, "")

    def getFreeSpotsCount(self, floor, vehicleType):
        return self.free_counts.get((floor, vehicleType), 0)
