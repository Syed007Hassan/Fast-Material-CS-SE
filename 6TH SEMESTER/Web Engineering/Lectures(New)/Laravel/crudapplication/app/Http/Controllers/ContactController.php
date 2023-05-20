<?php

namespace App\Http\Controllers;

use App\Models\Contact;
use Illuminate\Http\Request;


class ContactController extends Controller
{
    public function index()
    {
        $contacts = Contact::all();
        return view('contacts.index')->with('contacts', $contacts);
    }


    public function create()
    {
        return view('contacts.create');
    }


    public function store(Request $request)
    {
        $input = $request->all();
        Contact::create($input);
        return redirect('contact')->with('flash_message', 'Contact Addedd!');
    }


    public function show($id)
    {
        $contact = Contact::find($id);
        return view('contacts.show')->with('contacts', $contact);
    }


    public function edit($id)
    {
        $contact = Contact::find($id);
        return view('contacts.edit')->with('contacts', $contact);
    }


    public function update(Request $request, $id)
    {
        $contact = Contact::find($id);
        $input = $request->all();
        $contact->update($input);
        return redirect('contact')->with('flash_message', 'Contact Updated!');
    }


    public function destroy($id)
    {
        Contact::destroy($id);
        return redirect('contact')->with('flash_message', 'Contact deleted!');
    }
}
