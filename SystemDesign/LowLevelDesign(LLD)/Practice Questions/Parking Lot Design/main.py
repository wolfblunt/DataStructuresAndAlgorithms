from helper import Helper
from parking_lot import Solution

def main():
    parking = [[
        [4, 4, 2, 2],
        [2, 4, 2, 0],
        [0, 2, 2, 2],
        [4, 4, 4, 0]
    ]]
    helper = Helper()
    solution = Solution()
    solution.init(helper, parking)

    # Test park
    print("Parking 2-wheeler (bh234)...")
    spot_id = solution.park(2, "bh234", "tkt4534", 0)
    print("Allocated spot:", spot_id)

    # Test search
    print("Search by vehicle number(bh234):", solution.searchVehicle("bh234"))
    print("Search by ticket id(tkt4534):", solution.searchVehicle("tkt4534"))

    # Count free 2-wheeler spots
    print("Free 2-wheeler spots floor 0:", solution.getFreeSpotsCount(0, 2))

    # Remove vehicle
    print("Removing vehicle from spot", spot_id)
    print("Success:", solution.removeVehicle(spot_id))

    # Count free 2-wheeler spots again
    print("Free 2-wheeler spots floor 0:", solution.getFreeSpotsCount(0, 2))

if __name__ == "__main__":
    main()