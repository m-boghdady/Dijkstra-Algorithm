import pandas as pd

def convert_xlsx_to_csv(input_file, output_file):
    # Read the Excel file
    df = pd.read_excel(input_file, header=None)
    # Write to a CSV file
    df.to_csv(output_file, header=False, index=False)

# Example usage
convert_xlsx_to_csv('TestG.xlsx', 'TestG.csv')
convert_xlsx_to_csv('CitiesG.xlsx', 'CitiesG.csv')
