# Design a Parking Lot - Single Thread

## Overview

Write code for low-level design of a parking lot with multiple floors.

The parking lot has two kinds of parking spaces:  
- **Type 2**: For 2-wheeler vehicles  
- **Type 4**: For 4-wheeler vehicles

There are multiple floors in the parking lot. On each floor, vehicles are parked in parking spots arranged in rows and columns.

For simplicity, each floor has the same number of rows and each row has the same number of columns.

---

## Implementation Language

You can use either **Java** or **Python**.

---

## Implement the Below Methods in `Solution` Class

### `init(Helper helper, int[][][] parking)`

- `helper` provides methods like `helper.print("")` and `helper.println("")` for logging.
- `parking[i][j][k]` refers to the parking spot at:
  - `i`-th floor
  - `j`-th row
  - `k`-th column

### Parking Spot Types

- `4` → 4-wheeler parking spot  
- `2` → 2-wheeler parking spot  
- `0` → Inactive spot (no parking)

---

### `park(int vehicleType, String vehicleNumber, String ticketId, int parkingStrategy)`

**Returns**: `spotId` (Format: `floor-row-column`)

#### Responsibilities:
- Assign an empty parking spot to a vehicle.
- Map `vehicleNumber` and `ticketId` to the assigned `spotId`.

#### `parkingStrategy` Values:

- **Strategy 0**:  
  - Pick the **lowest index** spot (lowest floor, row, and column).

- **Strategy 1**:  
  - Choose the **floor with maximum number of free spots** for the given vehicle type.
  - If multiple floors have the same count, pick the **lowest index** floor among them.

---

### `removeVehicle(String spotId)`

**Returns**:
- `true` if vehicle was removed.
- `false` if vehicle not found or any error occurs.

---

### `searchVehicle(String query)`

**Returns**: The `spotId` (`e.g. 2-0-15`) where the vehicle is parked.  
If not found, returns an empty string `""`.

Query will be either:
- `vehicleNumber` or
- `ticketId`

---

### `getFreeSpotsCount(int floor, int vehicleType)`

**Returns**: Number of free spots of the specified vehicle type (2 or 4 wheeler) on the given floor.

Constraints:  
- `0 <= floor < parking.length`

---

## Constraints

- `vehicleType` = 2 or 4
- `1 <= floors <= 5`
- `1 <= rows <= 10,000`
- `1 <= columns <= 10,000`
- `1 <= rows * columns <= 10,000`

---

## Input Example

```python
parking = [[
    [4, 4, 2, 2],
    [2, 4, 2, 0],
    [0, 2, 2, 2],
    [4, 4, 4, 0]
]]
````

Explanation:

* 1 floor
* 4 rows × 4 columns
* Total:

  * 7 active 2-wheeler spots
  * 6 active 4-wheeler spots

---

## Example Function Calls

```python
park(2, "bh234", "tkt4534", 0)
# Returns: "0-0-2"
```

* Vehicle with number `"bh234"` is parked at floor `0`, row `0`, column `2`

```python
search("bh234")
# Returns: "0-0-2"

search("tkt4534")
# Returns: "0-0-2"
```

```python
getFreeSpotsCount(0, 2)
# Returns: 6
```

```python
removeVehicle("0-0-2")
# Returns: true
```

```python
getFreeSpotsCount(0, 2)
# Returns: 7
```

---

## Notes

* Spot IDs are in the format: `floor-row-column`
* Strategies help optimize either for locality (Strategy 0) or load distribution (Strategy 1)
