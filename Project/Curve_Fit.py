import tkinter as tk
from tkinter import ttk, messagebox, filedialog
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure
from scipy.optimize import curve_fit
import pandas as pd

class CurveFittingGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Automated Curve Fitting System")
        self.root.geometry("1200x800")
        
        # Initialize variables
        self.x_data = None
        self.y_data = None
        self.best_model = None
        self.best_params = None
        
        self.create_widgets()
        
    def create_widgets(self):
        # Main frame
        main_frame = ttk.Frame(self.root, padding="10")
        main_frame.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))
        
        # Configure grid weights
        self.root.columnconfigure(0, weight=1)
        self.root.rowconfigure(0, weight=1)
        main_frame.columnconfigure(1, weight=1)
        main_frame.rowconfigure(2, weight=1)
        
        # Data Input Section
        self.create_input_section(main_frame)
        
        # Results Section
        self.create_results_section(main_frame)
        
        # Plot Section
        self.create_plot_section(main_frame)
        
    def create_input_section(self, parent):
        # Input Frame
        input_frame = ttk.LabelFrame(parent, text="Data Input", padding="10")
        input_frame.grid(row=0, column=0, sticky=(tk.W, tk.E), padx=5, pady=5)
        
        # X Data Input
        ttk.Label(input_frame, text="X Data:").grid(row=0, column=0, sticky=tk.W)
        self.x_entry = tk.Text(input_frame, height=3, width=40)
        self.x_entry.grid(row=0, column=1, padx=5, pady=2)
        
        # Y Data Input
        ttk.Label(input_frame, text="Y Data:").grid(row=1, column=0, sticky=tk.W)
        self.y_entry = tk.Text(input_frame, height=3, width=40)
        self.y_entry.grid(row=1, column=1, padx=5, pady=2)
        
        # Buttons
        button_frame = ttk.Frame(input_frame)
        button_frame.grid(row=2, column=0, columnspan=2, pady=10)
        
        ttk.Button(button_frame, text="Load Sample Data", 
                  command=self.load_sample_data).pack(side=tk.LEFT, padx=5)
        ttk.Button(button_frame, text="Clear Data", 
                  command=self.clear_data).pack(side=tk.LEFT, padx=5)
        ttk.Button(button_frame, text="Fit Curve", 
                  command=self.fit_curve).pack(side=tk.LEFT, padx=5)
        ttk.Button(button_frame, text="Load from File", 
                  command=self.load_from_file).pack(side=tk.LEFT, padx=5)
        
    def create_results_section(self, parent):
        # Results Frame
        results_frame = ttk.LabelFrame(parent, text="Analysis Results", padding="10")
        results_frame.grid(row=0, column=1, sticky=(tk.W, tk.E, tk.N, tk.S), padx=5, pady=5)
        
        # Best Model
        ttk.Label(results_frame, text="Best Model:").grid(row=0, column=0, sticky=tk.W)
        self.model_var = tk.StringVar(value="None")
        self.model_label = ttk.Label(results_frame, textvariable=self.model_var, font=("Arial", 10, "bold"))
        self.model_label.grid(row=0, column=1, sticky=tk.W, padx=10)
        
        # Equation
        ttk.Label(results_frame, text="Equation:").grid(row=1, column=0, sticky=tk.W)
        self.equation_var = tk.StringVar(value="No equation fitted")
        self.equation_label = ttk.Label(results_frame, textvariable=self.equation_var, font=("Arial", 10))
        self.equation_label.grid(row=1, column=1, sticky=tk.W, padx=10)
        
        # Parameters
        ttk.Label(results_frame, text="Parameters:").grid(row=2, column=0, sticky=tk.W)
        self.params_text = tk.Text(results_frame, height=4, width=40)
        self.params_text.grid(row=2, column=1, padx=10, pady=5)
        
        # Fit Quality
        ttk.Label(results_frame, text="Fit Quality:").grid(row=3, column=0, sticky=tk.W)
        self.quality_text = tk.Text(results_frame, height=2, width=40)
        self.quality_text.grid(row=3, column=1, padx=10, pady=5)
        
    def create_plot_section(self, parent):
        # Plot Frame
        plot_frame = ttk.LabelFrame(parent, text="Visualization", padding="10")
        plot_frame.grid(row=2, column=0, columnspan=2, sticky=(tk.W, tk.E, tk.N, tk.S), padx=5, pady=5)
        
        # Create matplotlib figure
        self.fig = Figure(figsize=(10, 6), dpi=100)
        self.ax = self.fig.add_subplot(111)
        
        # Create canvas
        self.canvas = FigureCanvasTkAgg(self.fig, plot_frame)
        self.canvas.get_tk_widget().pack(fill=tk.BOTH, expand=True)
        
        # Initialize empty plot
        self.ax.set_title("Curve Fitting Results")
        self.ax.set_xlabel("X")
        self.ax.set_ylabel("Y")
        self.ax.grid(True, alpha=0.3)
        
    def parse_data(self, data_str):
        """Parse comma or space separated data string into numpy array"""
        try:
            # Replace commas with spaces and split
            data_str = data_str.replace(',', ' ')
            data_list = [float(x) for x in data_str.split() if x.strip()]
            return np.array(data_list)
        except ValueError:
            return None
            
    def load_sample_data(self):
        """Load sample data for demonstration"""
        sample_x = "1, 2, 3, 4, 5, 6, 7, 8, 9"
        sample_y = "2.5, 3.6, 7.1, 8.3, 11.4, 12.9, 15.5, 16.8, 19.0"
        
        self.x_entry.delete(1.0, tk.END)
        self.x_entry.insert(1.0, sample_x)
        
        self.y_entry.delete(1.0, tk.END)
        self.y_entry.insert(1.0, sample_y)
        
    def clear_data(self):
        """Clear all input fields and results"""
        self.x_entry.delete(1.0, tk.END)
        self.y_entry.delete(1.0, tk.END)
        self.model_var.set("None")
        self.equation_var.set("No equation fitted")
        self.params_text.delete(1.0, tk.END)
        self.quality_text.delete(1.0, tk.END)
        self.ax.clear()
        self.ax.set_title("Curve Fitting Results")
        self.ax.set_xlabel("X")
        self.ax.set_ylabel("Y")
        self.ax.grid(True, alpha=0.3)
        self.canvas.draw()
        
    def load_from_file(self):
        """Load data from CSV file"""
        file_path = filedialog.askopenfilename(
            title="Select Data File",
            filetypes=[("CSV files", "*.csv"), ("Text files", "*.txt"), ("All files", "*.*")]
        )
        
        if file_path:
            try:
                # Try to read as CSV
                df = pd.read_csv(file_path)
                if len(df.columns) >= 2:
                    x_data = df.iloc[:, 0].values
                    y_data = df.iloc[:, 1].values
                    
                    self.x_entry.delete(1.0, tk.END)
                    self.x_entry.insert(1.0, ', '.join(map(str, x_data)))
                    
                    self.y_entry.delete(1.0, tk.END)
                    self.y_entry.insert(1.0, ', '.join(map(str, y_data)))
                    
                    messagebox.showinfo("Success", "Data loaded successfully!")
                else:
                    messagebox.showerror("Error", "File must have at least 2 columns")
            except Exception as e:
                messagebox.showerror("Error", f"Failed to load file: {str(e)}")
    
    # Model functions
    def linear_model(self, x, a, b):
        return a * x + b
        
    def quadratic_model(self, x, a, b, c):
        return a + b * x + c * x**2
        
    def exponential_model(self, x, a, b):
        return a * np.exp(b * x)

        
    def fit_curve(self):
        """Main curve fitting function"""
        # Get data from input fields
        x_str = self.x_entry.get(1.0, tk.END).strip()
        y_str = self.y_entry.get(1.0, tk.END).strip()
        
        if not x_str or not y_str:
            messagebox.showerror("Error", "Please enter both X and Y data")
            return
            
        # Parse data
        self.x_data = self.parse_data(x_str)
        self.y_data = self.parse_data(y_str)
        
        if self.x_data is None or self.y_data is None:
            messagebox.showerror("Error", "Invalid data format. Use numbers separated by commas or spaces.")
            return
            
        if len(self.x_data) != len(self.y_data):
            messagebox.showerror("Error", "X and Y data must have the same number of points")
            return
            
        if len(self.x_data) < 2:
            messagebox.showerror("Error", "At least 2 data points are required")
            return
            
        # Fit models
        self.fit_best_model()
        
        # Update display
        self.update_results()
        
        # Update plot
        self.update_plot()
        
    def fit_best_model(self):
        """Find the best fitting model"""
        models = {
            'Linear': self.linear_model,
            'Quadratic': self.quadratic_model,
            'Exponential': self.exponential_model
        }
        
        best_model_name = None
        best_params = None
        best_sum_sq_res = np.inf
        model_results = {}
        
        for name, model_func in models.items():
            try:
                # Initial parameter guesses
                if name == 'Linear':
                    p0 = [1, 0]
                elif name == 'Quadratic':
                    p0 = [1, 1, 0]
                elif name == 'Exponential':
                    p0 = [1, 0.1, 0]
                elif name == 'Power Law':
                    p0 = [1, 1]
                
                params, covariance = curve_fit(model_func, self.x_data, self.y_data, 
                                             p0=p0, maxfev=10000)
                
                # Calculate residuals
                y_pred = model_func(self.x_data, *params)
                residuals = self.y_data - y_pred
                sum_sq_res = np.sum(residuals**2)
                
                # Calculate R-squared
                ss_tot = np.sum((self.y_data - np.mean(self.y_data))**2)
                r_squared = 1 - (sum_sq_res / ss_tot)
                
                model_results[name] = {
                    'params': params,
                    'sum_sq_res': sum_sq_res,
                    'r_squared': r_squared,
                    'covariance': covariance
                }
                
                if sum_sq_res < best_sum_sq_res:
                    best_sum_sq_res = sum_sq_res
                    best_model_name = name
                    best_params = params
                    
            except Exception as e:
                print(f"Failed to fit {name} model: {e}")
                continue
                
        self.best_model = best_model_name
        self.best_params = best_params
        self.model_results = model_results
        
    def get_equation_string(self):
        """Generate equation string based on best model"""
        if self.best_model is None or self.best_params is None:
            return "No equation fitted"
            
        params = self.best_params
        
        if self.best_model == 'Linear':
            return f"y = {params[0]:.3f}x + {params[1]:.3f}"
        elif self.best_model == 'Quadratic':
            return f"y = {params[0]:.3f}x² + {params[1]:.3f}x + {params[2]:.3f}"
        elif self.best_model == 'Exponential':
            return f"y = {params[0]:.3f}e^({params[1]:.3f}x) + {params[2]:.3f}"
        elif self.best_model == 'Power Law':
            return f"y = {params[0]:.3f}x^{params[1]:.3f}"
        
        return "Unknown model"
        
    def update_results(self):
        """Update the results display"""
        if self.best_model is None:
            self.model_var.set("No suitable model found")
            return
            
        # Update model name
        self.model_var.set(self.best_model)
        
        # Update equation
        equation_str = self.get_equation_string()
        self.equation_var.set(equation_str)
        
        # Update parameters
        self.params_text.delete(1.0, tk.END)
        if self.best_model in self.model_results:
            params = self.model_results[self.best_model]['params']
            param_names = {
                'Linear': ['a (slope)', 'b (intercept)'],
                'Quadratic': ['a (x²)', 'b (x)', 'c (constant)'],
                'Exponential': ['a (amplitude)', 'b (rate)', 'c (offset)']
            }
            
            names = param_names.get(self.best_model, [f'param_{i}' for i in range(len(params))])
            
            for i, (name, value) in enumerate(zip(names, params)):
                self.params_text.insert(tk.END, f"{name}: {value:.6f}\n")
        
        # Update fit quality
        self.quality_text.delete(1.0, tk.END)
        if self.best_model in self.model_results:
            results = self.model_results[self.best_model]
            self.quality_text.insert(tk.END, f"R²: {results['r_squared']:.6f}\n")
            self.quality_text.insert(tk.END, f"Sum of Squared Residuals: {results['sum_sq_res']:.6f}")
            
    def update_plot(self):
        """Update the plot with data and fitted curve"""
        self.ax.clear()
        
        # Plot original data points
        self.ax.scatter(self.x_data, self.y_data, color='blue', s=50, alpha=0.7, label='Data Points')
        
        # Plot fitted curve
        if self.best_model is not None and self.best_params is not None:
            x_smooth = np.linspace(min(self.x_data), max(self.x_data), 100)
            
            model_func = {
                'Linear': self.linear_model,
                'Quadratic': self.quadratic_model,
                'Exponential': self.exponential_model
            }[self.best_model]
            
            try:
                y_smooth = model_func(x_smooth, *self.best_params)
                self.ax.plot(x_smooth, y_smooth, 'r-', linewidth=2, 
                           label=f'Fitted {self.best_model} Curve')
            except Exception as e:
                print(f"Error plotting curve: {e}")
        
        # Customize plot
        self.ax.set_title(f"Curve Fitting Results - {self.best_model if self.best_model else 'No Model'}")
        self.ax.set_xlabel("X")
        self.ax.set_ylabel("Y")
        self.ax.grid(True, alpha=0.3)
        self.ax.legend()
        
        # Refresh canvas
        self.canvas.draw()

# Main application
if __name__ == "__main__":
    root = tk.Tk()
    app = CurveFittingGUI(root)
    root.mainloop()
