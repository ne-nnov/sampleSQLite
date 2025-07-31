# SQLite Threaded Counter Sample
A demonstration application that:
- Populates an SQLite database with counter values,
- Increments values in a background thread,
- Displays real-time increment frequency.

## Features
- Thread-safe counter operations,
- Real-time frequency calculation,
- SQLite database persistence,
- Interactive UI controls.

### Requirements
- CMake 3.29.2 or later,
- Visual Studio 2022,
- Qt-6.4.2.

### Build Instructions
1. Run CMake.
2. Configure project:
   - Set source directory,
   - Set build directory,
   - Click 'Configure'.
3. Set variables:
   - `Qt6_DIR`: Path to Qt installation directory,
   - `INSTALL_DIR`:  Target installation directory (defaults to `{CMAKE_BINARY_DIR}/install` if unspecified).
4. Generate project files.
5. Open solution in Visual Studio 2022.
6. Build and install.
7. Run from installation directory.

## Usage
1. Launch the application.
2. Monitor the increment frequency using the 'Counter Increment Frequency' label.
3. View current counter values in the 'Counter' table.
4. Button controls:
 - add - inserts a new counter,
 - remove - deletes the selected counter,
 - save - persists all counter states to the database file,
 - more - shows advanced controls for tracking the process.
5. Advanced controls:
 - start - resumes counter increment process,
 - stop - pauses counter increment process,
 - SQLite - toggles database content table visibility,
 - add 1000 - bulk-inserts 1000 counters,
 - sum field - displays total sum of counters at time t0,
 - sec: field - shows elapsed time (t1-t0) in seconds.

## Technical Notes
- Thread synchronization via STL library.
- SQLite database file location: {executable_directory}/testSqlBase.sqlite3.
- Frequency calculation:
  Frequency = ((Sum of all counters at time t1) - (Sum of all counters at time t0)) / (t1 - t0)
  Time is in seconds.