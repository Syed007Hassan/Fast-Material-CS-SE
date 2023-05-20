<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Employee;

class EmployeeController extends Controller
{
    public function index()
    {
        $employees = Employee::all();
        return view('employees.index')->with('employees', $employees);
    }
    public function create()
    {
        return view('employees.create');
    }
    public function store(Request $request)
    {
        $requestData = $request->all();
        $fileName = time() . $request->file('photo')->getClientOriginalName();
        $path = $request->file('photo')->storeAs('images', $fileName, 'public');
        $requestData["photo"] = '/storage/' . $path;
        Employee::create($requestData);
        return redirect('employee')->with('flash_message', 'Employee Addedd!');

        /* store the image to /storage/app/public/images/ use above code for help */
    }
}
