import re
from datetime import datetime

# Define custom exceptions
class InvalidDateFormat(Exception):
    pass

class InvalidMonthName(Exception):
    pass

def extract_datetime(dateTimeString):
    # Regex patterns for each format
    patterns = [
        r"^(?P<year>\d{4})[-/](?P<month>\d{1,2})[-/](?P<day>\d{1,2}) (?P<hour>\d{2}):(?P<minute>\d{2}):(?P<second>\d{2})$",  # YYYY-MM-DD HH:mm:ss or YYYY/MM/DD HH:mm:ss
        r"^(?P<day>\d{1,2}) (?P<month>\w+) (?P<year>\d{4}) (?P<hour>\d{2}):(?P<minute>\d{2}):(?P<second>\d{2})$"  # DD Month YYYY HH:mm:ss
    ]
    
    # Dictionary for month conversion
    month_names = {
        'january': 1, 'february': 2, 'march': 3, 'april': 4, 'may': 5, 'june': 6,
        'july': 7, 'august': 8, 'september': 9, 'october': 10, 'november': 11, 'december': 12
    }
    
    # Try to match each pattern
    for pattern in patterns:
        match = re.match(pattern, dateTimeString, re.IGNORECASE)
        if match:
            components = match.groupdict()
            
            # Convert month to numeric if it's in string format
            if components['month'].isalpha():
                month_name = components['month'].lower()
                if month_name in month_names:
                    components['month'] = month_names[month_name]
                else:
                    raise InvalidMonthName("Invalid month name")
            else:
                components['month'] = int(components['month'])
            
            # Convert other components to integers
            components = {k: int(v) for k, v in components.items()}
            
            # Validate date and time
            try:
                datetime(
                    components['year'], components['month'], components['day'],
                    components['hour'], components['minute'], components['second']
                )
            except ValueError:
                raise InvalidDateFormat("Invalid date or time format")
            
            # Return formatted string
            return f"Year: {components['year']}, Month: {components['month']}, Day: {components['day']}, " \
                   f"Hour: {components['hour']}, Minute: {components['minute']}, Second: {components['second']}"
    
    # If no pattern matched
    raise InvalidDateFormat("Invalid date and time format")

# Example usage:
try:
    result = extract_datetime("2024/02/21 12:30:45")
    print(result)
except Exception as e:
    print(str(e))

# try:
#     result = extract_datetime("29 September 2024 15:45:30")
#     print(result)
# except Exception as e:
#     print(str(e))