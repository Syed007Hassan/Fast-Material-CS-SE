<?php

namespace App\Http\Controllers;

use App\Models\Customer;
use Illuminate\Http\RedirectResponse;
use Illuminate\Http\Request;
use Illuminate\Http\Response;
use Illuminate\View\View;

class CustomerController extends Controller
{


    public function index(): View
    {
        $customers = Customer::latest()->paginate(5);

        return view('customers.index', compact('customers'));
    }


    public function show(Customer $customer): View
    {
        return view('customers.show', compact('customer'));
    }


    public function create(): View
    {
        return view('customers.create');
    }


    public function store(Request $request): RedirectResponse
    {
        $request->validate([
            'name' => 'required',
            'email' => 'required',
            'city' => 'required',
            'roomType' => 'required',
        ]);

        Customer::create($request->all());

        return redirect()->route('customers.index')
            ->with('success', 'Customer created successfully.');
    }


    public function edit(Customer $customer): View
    {

        return view('customers.edit', compact('customer'));
    }

    public function update(Request $request, Customer $customer): RedirectResponse
    {
        $request->validate([
            'name' => 'required',
            'email' => 'required',
            'city' => 'required',
            'roomType' => 'required',
        ]);

        $customer->update($request->all());

        return redirect()->route('customers.index')
            ->with('success', 'Customer updated successfully');
    }


    public function destroy(Customer $customer): RedirectResponse
    {

        $customer->delete();


        return redirect()->route('customers.index')
            ->with('success', 'Customer deleted successfully');
    }
}
